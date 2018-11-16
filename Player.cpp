#include "Player.h"
#include "Rad.h"
#include "Hud.h"
#include "Item.h"
#include "Spell.h"

#include <sstream>

// Constructors and Destructors //

Player::Player(Rad *t, Character* c)
{
	rad = t;
	character = c;
	cameraX = 0;
	cameraY = 0;
}

Player::~Player()
{
}

// Functions //

// Getters:

Character* Player::getCharacter() {
	return character;
}

int Player::getCameraX()
{
	return cameraX;
}

int Player::getCameraY()
{
	return cameraY;
}

string Player::getMessage()
{
	return character->getMessage();
}

// Setters:

void Player::setCharacter(Character* c) {
	character = c;
}

void Player::setMessage(string s)
{
	if (character->getMessage() != "")
	{
		messageLog.push_back(character->getMessage());
		if (messageLog.size() > 50)
		{
			messageLog.erase(messageLog.begin());
		}
	}
	character->setMessage(s);
}

// Misc:

void Player::control(int inChar)
{
	controlWaiting(inChar);
	controlMovement(inChar);
	controlAttack(inChar);
	controlLog(inChar);
	controlInventory(inChar);
	controlCharacterSheet(inChar);
}

void Player::centreCamera()
{
	cameraX = round(character->getX());
	cameraY = round(character->getY());
}

void Player::controlWaiting(int inChar)
{	
	if (inChar == '.')
	{
		rad->turnCompleted(ACTION_WAIT);
	}
}

void Player::controlMovement(int inChar)
{	
	if (inChar == 'a' || inChar == 'd' || inChar == 'w' || inChar == 's' || inChar == 'q' || inChar == 'e' || inChar == 'z' || inChar == 'c')
	{
		bool moved = false;
		int mX = 0;
		int mY = 0;
		if (inChar == 'a')
		{
			mX = -1;
		}
		if (inChar == 'd')
		{
			mX = 1;
		}
		if (inChar == 'w')
		{
			mY = 1;
		}
		if ( inChar == 's')
		{
			mY = -1;
		}
		if (inChar == 'q')
		{
			mX = -1;
			mY = 1;
		}
		if (inChar == 'e')
		{
			mX = 1;
			mY = 1;
		}
		if (inChar == 'z')
		{
			mX = -1;
			mY = -1;
		}
		if ( inChar == 'c')
		{
			mX = 1;
			mY = -1;
		}
		moved = character->moveBy(mX, mY);
		centreCamera();
		
		if (moved)
		{
			rad->turnCompleted(ACTION_MOVE);
		}
		else
		{
			rad->attackAt(character->getX() + mX, character->getY() + mY, character, false);
			rad->turnCompleted(ACTION_ATTACK);
		}
	}
	if (inChar == '>')
	{
		character->setXP(character->getXP() + 10);
		if (rad->goDownStairs())
		{
			rad->turnCompleted(ACTION_MOVE);
		}
	}
}

void Player::controlAttack(int inChar)
{	
	bool attacked = false;
	bool success;
	if (inChar == 'f')
	{
		setMessage("Attack in which direction?");
		rad->draw();
		int inChar = getch();
		if (inChar == 'a' || inChar == 'd' || inChar == 'w' || inChar == 's' || inChar == 'q' || inChar == 'e' || inChar == 'z' || inChar == 'c')
		{
			bool moved = false;
			int mX = 0;
			int mY = 0;
			if (inChar == 'a')
			{
				mX = -1;
			}
			if (inChar == 'd')
			{
				mX = 1;
			}
			if (inChar == 'w')
			{
				mY = 1;
			}
			if ( inChar == 's')
			{
				mY = -1;
			}
			if (inChar == 'q')
			{
				mX = -1;
				mY = 1;
			}
			if (inChar == 'e')
			{
				mX = 1;
				mY = 1;
			}
			if (inChar == 'z')
			{
				mX = -1;
				mY = -1;
			}
			if ( inChar == 'c')
			{
				mX = 1;
				mY = -1;
			}
			
			if (mX == 0 && mY == 0)
			{
				attacked = false;
				rad->turnCompleted(ACTION_FREE);
			}
			else
			{			
				attacked = true;
				success = rad->attackAt(character->getX() + mX, character->getY() + mY, character, true);
			}
		}
		if (attacked)
		{
			if (!success)
			{
				//setMessage(character->getName() + " attacked thin air.");
			}
			rad->turnCompleted(ACTION_ATTACK);
		}
		else
		{
			setMessage("Never mind.");
			rad->turnCompleted(ACTION_FREE);
		}
	}
}

void Player::controlLog(int inChar)
{	
	if (inChar == 'l')
	{
		showLog();
	}
}

void Player::controlInventory(int inChar)
{
	if (inChar == 'i')
	{
		if (character->getItems().size() == 0)
		{
			setMessage("Inventory is empty");
			return;
		}
		vector<string> itemNames;
		for (int i = 0; i < character->getItems().size(); i++)
		{
			itemNames.push_back(character->getItems()[i]->itemString());
		}
		setMessage("Inventory");
		int selectedItem = rad->showMenu(itemNames, true);
		
		if (selectedItem == -1)
		{
			setMessage("");
			return;
		}
		else
		{
			if (character->getItems()[selectedItem]->getItemType() == ITEM_ARMOR)
			{
				setMessage("e: equip/unequip, d: drop, any other key: cancel");
				rad->draw();
				int inChar = getch();
				if (inChar == 'e')
				{
					if (character->getItems()[selectedItem]->equip(character->getItems()))
					{						
						rad->turnCompleted(ACTION_EQUIP_ARMOR);
						character->setMessage("");
						return;
					}
					else
					{
						if (character->getItems()[selectedItem]->getItemType() == ITEM_ARMOR)
							setMessage("You can only wear one set of armor at a time.");
						return;
					}
				}
				else if (inChar == 'd')
				{
					if (character->getItems()[selectedItem]->drop(character->getItems()))
					{
						character->getItems().erase(character->getItems().begin() + selectedItem);
						
						character->setMessage("");
						return;
					}
					else
					{
						setMessage("You cannot drop items that you have equipped.");
						return;
					}
				}
				else
				{
					setMessage("Never mind.");
					return;
				}
			}
			else if (character->getItems()[selectedItem]->getItemType() == ITEM_WEAPON)
			{
				setMessage("e: equip/unequip, d: drop, any other key: cancel");
				rad->draw();
				int inChar = getch();
				if (inChar == 'e')
				{
					if (character->getItems()[selectedItem]->equip(character->getItems()))
					{						
						rad->turnCompleted(ACTION_EQUIP_ITEM);
						character->setMessage("");
						return;
					}
					else
					{
						if (character->getItems()[selectedItem]->getItemType() == ITEM_WEAPON)
							setMessage("You are already wielding a weapon");
						return;
					}
				}
				else if (inChar == 'd')
				{
					if (character->getItems()[selectedItem]->drop(character->getItems()))
					{
						character->getItems().erase(character->getItems().begin() + selectedItem);
						
						setMessage("");
						return;
					}
					else
					{
						setMessage("You cannot drop items that you have equipped.");
						return;
					}
				}
				else
				{
					setMessage("Never mind.");
					return;
				}
			}
			if (character->getItems()[selectedItem]->getItemType() == ITEM_AMULET)
			{
				setMessage("e: equip/unequip, d: drop, any other key: cancel");
				rad->draw();
				int inChar = getch();
				if (inChar == 'e')
				{
					if (character->getItems()[selectedItem]->equip(character->getItems()))
					{						
						rad->turnCompleted(ACTION_EQUIP_ITEM);
						character->setMessage("");
						return;
					}
					else
					{
						if (character->getItems()[selectedItem]->getItemType() == ITEM_AMULET)
							setMessage("You can only wear one amulet at a time.");
						return;
					}
				}
				else if (inChar == 'd')
				{
					if (character->getItems()[selectedItem]->drop(character->getItems()))
					{
						character->getItems().erase(character->getItems().begin() + selectedItem);
						
						character->setMessage("");
						return;
					}
					else
					{
						setMessage("You cannot drop items that you have equipped.");
						return;
					}
				}
				else
				{
					setMessage("Never mind.");
					return;
				}
			}
			if (character->getItems()[selectedItem]->getItemType() == ITEM_MISC || character->getItems()[selectedItem]->getItemType() == ITEM_POTION)
			{
				setMessage("u: use, d: drop, any other key: cancel");
				rad->draw();
				int inChar = getch();
				if (inChar == 'u')
				{
					if (character->getItems()[selectedItem]->use(character))
					{						
						rad->turnCompleted(ACTION_USE_ITEM);
						character->getItems().erase(character->getItems().begin() + selectedItem);
						character->setMessage("");
						return;
					}
					else
					{
						setMessage("You cannot use that item right now.");
						return;
					}
				}
				else if (inChar == 'd')
				{
					if (character->getItems()[selectedItem]->drop(character->getItems()))
					{
						character->getItems().erase(character->getItems().begin() + selectedItem);
						
						character->setMessage("");
						return;
					}
					else
					{
						setMessage("You cannot drop that item.");
						return;
					}
				}
				else
				{
					setMessage("Never mind.");
					return;
				}
			}
			if (character->getItems()[selectedItem]->getItemType() == ITEM_SCROLL)
			{
				setMessage("u: use, l: learn, d: drop, any other key: cancel");
				rad->draw();
				int inChar = getch();
				if (inChar == 'u')
				{
					if (character->getItems()[selectedItem]->use(character))
					{						
						character->getItems().erase(character->getItems().begin() + selectedItem);
						rad->turnCompleted(ACTION_USE_ITEM);
						return;
					}
					else
					{
						rad->turnCompleted(ACTION_USE_ITEM);
						return;
					}
				}
				else if (inChar == 'l')
				{
					Spell* spell = new Spell(rad, character->getItems()[selectedItem]->getName());
					if (character->learnSpell(spell))
					{
						character->getItems().erase(character->getItems().begin() + selectedItem);
						rad->turnCompleted(ACTION_LEARN_SPELL);
						return;
					}
					else
					{
						rad->turnCompleted(ACTION_LEARN_SPELL);
						return;
					}
				}
				else if (inChar == 'd')
				{
					if (character->getItems()[selectedItem]->drop(character->getItems()))
					{
						character->getItems().erase(character->getItems().begin() + selectedItem);
						
						character->setMessage("");
						return;
					}
					else
					{
						setMessage("You cannot drop that item.");
						return;
					}
				}
				else
				{
					setMessage("Never mind.");
					return;
				}
			}

		}
		
		setMessage("");
	}
}

void Player::controlCharacterSheet(int inChar)
{	
	if (inChar == 'p')
	{
		character->showCharacterSheet();
	}	
}

void Player::chooseDirection(int* dx, int* dy, string message)
{
	setMessage(message);
	rad->draw();
	int inChar = getch();
	if (inChar == 'a')
	{
		*dx = -1;
		*dy = 0;
	}
	else if (inChar == 'd')
	{
		*dx = 1;
		*dy = 0;
	}
	else if (inChar == 'w')
	{
		*dx = 0;
		*dy = 1;
	}
	else if ( inChar == 's')
	{
		*dx = 0;
		*dy = -1;
	}
	else if (inChar == 'q')
	{
		*dx = -1;
		*dy = 1;
	}
	else if (inChar == 'e')
	{
		*dx = 1;
		*dy = 1;
	}
	else if (inChar == 'z')
	{
		*dx = -1;
		*dy = -1;
	}
	else if ( inChar == 'c')
	{
		*dx = 1;
		*dy = -1;
	}
	else if ( inChar == '.')
	{
		*dx = 0;
		*dy = 0;
	}
}

void Player::showLog()
{	
	rad->showMenu(messageLog, false);
}
