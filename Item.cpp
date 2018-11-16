#include "Item.h"
#include "Rad.h"
#include "Character.h"
#include "Spell.h"
#include "Weapon.h"

// Constructors and Destructors //

Item::Item(Rad* t, int i, int l, string n, int v, bool d, bool e)
	:Entity(t)
{
	itemType = i;
	level = l;
	if (itemType == ITEM_ARMOR)
	{
		graphic = new Graphic('[', COLOR_WHITE);
	}
	else if (itemType == ITEM_WEAPON)
	{
		graphic = new Graphic(')', COLOR_WHITE);
	}
	else if (itemType == ITEM_MISC)
	{
		graphic = new Graphic('(', COLOR_WHITE);
	}
	else if (itemType == ITEM_AMULET)
	{
		graphic = new Graphic('"', COLOR_WHITE);
	}
	else if (itemType == ITEM_POTION)
	{
		graphic = new Graphic('!', COLOR_WHITE);
	}
	else if (itemType == ITEM_SCROLL)
	{
		graphic = new Graphic('?', COLOR_WHITE);
	}
	else if (itemType == ITEM_AMMO)
	{
		graphic = new Graphic(')', COLOR_WHITE);
	}
	name = n;
	value = v;
	identified = d;
	equipped = e;
}

// Functions //

// Getters:

Actor* Item::getActor()
{
	return NULL;
}

int Item::getItemType() const
{
	return itemType;
}

int Item::getLevel() const
{
	return level;
}

string Item::getName() const
{
	return name;
}

int Item::getValue() const
{
	return value;
}

bool Item::getIdentified() const
{
	return identified;
}

bool Item::getEquipped() const
{
	return equipped;
}

// Setters:

void Item::setName(string s)
{
	name = s;
}

void Item::setValue(int v)
{
	value = v;
}

// Misc:

void Item::update()
{
}

string Item::itemString()
{
	string s = "";
	if (itemType == ITEM_ARMOR || itemType == ITEM_WEAPON || itemType == ITEM_AMULET)
	{
		s += graphic->getCharacter();
		if (identified)
		{
			s += " +";
			stringstream stream;
			stream << value;
			s += stream.str();
		}
		s += " ";
		s += name;
		if (equipped)
		{
			s += " (equipped)";
		}
	}
	else if (itemType == ITEM_MISC || itemType == ITEM_POTION)
	{
		s += graphic->getCharacter();
		s += " ";
		s += name;
	}
	else if (itemType == ITEM_SCROLL)
	{
		s += graphic->getCharacter();
		s += " ";
		s += "Scroll of " + name;
	}
	else if (itemType == ITEM_AMMO) {
		s += graphic->getCharacter();
		s += " ";
		stringstream stream;
		stream << value;
		s += stream.str();
		s += " ";
		s += name;
	}
	return s;
}

bool Item::equip(vector<Item*> v)
{
	if (equipped)
	{
		equipped = false;
		return true;
	}
	else
	{
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i]->getItemType() == itemType && v[i]->getEquipped())
			{
				return false;
			}
		}
		equipped = true;
		return true;
	}
}

bool Item::drop(vector<Item*> v)
{
	if (equipped)
	{
		return false;
	}
	else
	{
		return true;
	}
	return false;
}

bool Item::use(Character* character)
{
	if (itemType == ITEM_POTION)
	{
		if (name == "Potion of Healing")
		{
			// heal the character
			return true;
		}
	}
	if (itemType == ITEM_SCROLL)
	{		
		/*(Spell* scrollSpell = new Spell(rad, name);
		if (rad->d(20) + character->getLore() < (20 + (2 * scrollSpell->getLevel()) - 1))
		{
			character->setMessage(character->getName() + " failed to read the scroll correctly.");
			return false;
		}
		int dx = 99;
		int dy = 99;
		rad->getPlayer()->chooseDirection(&dx, &dy, "Cast spell in which direction?");
		return scrollSpell->castFromScroll(character, dx, dy);*/
	}
	return false;
}
