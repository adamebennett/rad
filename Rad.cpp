#include "Rad.h"
#include "Player.h"
#include "NPC.h"
#include "Character.h"
#include "Soldier.h"
#include "Hacker.h"
#include "Theurge.h"
#include "Item.h"
#include "Weapon.h"
#include "Projectile.h"

#include <sstream>
#include <math.h>

#ifdef ALLOW_DELAYS
	#ifdef WINDOWS_DELAYS
		#include <windows.h>
	#endif
	#ifdef POSIX_DELAYS
		#include <unistd.h>
	#endif
#endif

// Constructors and Destructors //

Rad::Rad(Graphics* g)
{
	srand(unsigned(time(NULL)));
	graphics = g;
	player = new Player(this, NULL);
	level = 0;
	
	// player and graphics must be allocated before hud
	hud = new Hud(this, graphics, player, '-');
	
	// graphics must be allocated before tiles
	tiles = new TileMap(graphics, this, level);
}

Rad::~Rad()
{
	// hud must be deallocated before player and graphics
	delete(hud);
	
	delete(player);
	
	delete(tiles);
	
	for (int i = 0; i < entities.size(); i++)
	{
		if (entities[i] != NULL)
		{
			delete(entities[i]);
		}
	}
}

// Functions //

// Getters:

vector<Entity*>* Rad::getEntities()
{
	return &entities;
}

int Rad::getTurns()
{
	return turns;
}

Player* Rad::getPlayer()
{
	return player;
}

// Misc:

void Rad::initialize(Character* c)
{
	turns = 0;
	graphics->clearScreen();
	player->setCharacter(c);
	player->getCharacter()->setGraphic(new Graphic('@', COLOR_WHITE, COLOR_BLUE));
	entities.push_back(player->getCharacter());
	tiles->positionPlayer(player);
	player->centreCamera();
	player->getCharacter()->update();
	player->centreCamera();
	
	for (int i = 0; i < 100; ++i)
	{
		NPC* npc = tiles->placeNPC(player->getCharacter());
		if (npc != NULL)
		{
			npc->getCharacter()->initializeAbilityScores();
			npc->getCharacter()->initializeStats();
			npc->getCharacter()->initializeSpells();
			entities.push_back(npc->getCharacter());
		}
	}
	
	revealTiles();
	draw();
	mainLoop();
}

int Rad::d(int sides)
{
	return ((rand() % (int)(sides)) + 1);
}

int Rad::numD(int num, int sides)
{
	int total = 0;
	for (int i = 0; i < num; ++i)
	{
		total += d(sides);
	}
	return total;
}

int Rad::calculateModifier(int score)
{
	int modifier = (int)(floor((score - 10) / 2.0));
	return modifier;
}

void Rad::mainLoop()
{
	while (true)
	{
		int inChar = ' ';
		
		while (true)
		{			
			inChar = getch();
			player->setMessage("");
			player->control(inChar);
			draw();
			if (player->getCharacter()->getHealth() <= 0)
			{
				player->setMessage("Game Over. Press Enter, Backspace, or Esc to return to the main menu.");
				player->showLog();
				return;
			}
		}
	}
}

void Rad::turnCompleted(int duration)
{
	for (int i = 0; i < duration; ++i)
	{
		for (int i = 0; i < entities.size(); ++i)
		{
			if (entities[i]->getActor() != NULL && entities[i]->getActor() != player) {
				entities[i]->getActor()->control(0);
			}
			entities[i]->update();
		}
		turns += duration;
		revealTiles();
		draw();
	}
}

void Rad::revealTiles()
{
	tiles->hide();
	for (int a = 0; a < 360; ++a)
	{
		int x = player->getCharacter()->getX();
		int y = player->getCharacter()->getY();
		int z = 0;
		while (z < DRAW_DIST && x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT)
		{
			tiles->setVisible(x,y,true);
			tiles->setRevealed(x,y,true);
			if (tiles->isSolid(x,y))
			{
				break;
			}
			z++;
			float r = a * (PI / 180.0);
			x = player->getCharacter()->getX() + (int)(round(cos(r)*z));
			y = player->getCharacter()->getY() + (int)(round(sin(r)*z));
		}		
	}
}

void Rad::draw()
{
	graphics->clearScreen();
	tiles->draw(-player->getCameraX(), -player->getCameraY());
	drawEntities(entities);
	hud->draw();
	graphics->refreshScreen();
}

void Rad::drawEntities(vector<Entity*>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (canSee(player->getCharacter(), v[i]))
		{
			graphics->drawGraphicInvertedCentred(v[i]->getGraphic(), -player->getCameraX(), -player->getCameraY());
		}
	}
	graphics->drawGraphicInvertedCentred(player->getCharacter()->getGraphic(), -player->getCameraX(), -player->getCameraY());
}

bool Rad::isSolid(int x, int y)
{
	for (int i = 0; i < entities.size(); ++i)
	{
		if (entities[i]->getActor() != NULL && entities[i]->getX() == x && entities[i]->getY() == y)
		{
			return true;
		}
	}
	return tiles->isSolid(x, y);
}

bool Rad::isMapSolid(int x, int y)
{
	return tiles->isSolid(x, y);
}

void Rad::addEntity(Entity* e, vector<Entity*>& v)
{
	v.push_back(e);
}

void Rad::removeEntity(Entity* e, vector<Entity*>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == e)
		{
			v.erase(v.begin() + i);
			break;
		}
	}
}

int Rad::showMenu(vector<string> v, bool isMenu)
{
	return hud->showMenu(v, isMenu);
}

bool Rad::canSee(Character* from, Entity* to)
{
	float r = atan2(to->getY() - from->getY(), to->getX() - from->getX());
	
	int x = from->getX();
	int y = from->getY();
	int z = 0;
	int dist = round(sqrt(pow(to->getX() - from->getX(), 2) + pow(to->getY() - from->getY(), 2)));
	while (z < DRAW_DIST && z < dist && x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT)
	{
		if (isMapSolid(x, y))
		{
			return false;
		}
		z += 1;
		x = from->getX() + round(cos(r)*z);
		y = from->getY() + round(sin(r)*z);
	}
	return true;
}

bool Rad::attackAt(int x, int y, Character* c, bool force)
{	
	bool result = false;
	
	if (c->useWeapon() == false) {
		if (c == player->getCharacter()) {
			player->setMessage("No ammunition");
		}
		return false;
	}
	
	if (!c->ranged())
	{
		for (int i = 0; i < entities.size(); ++i)
		{
			if (entities[i]->getActor() && entities[i]->getX() == x && entities[i]->getY() == y)
			{
				Character* target = (Character*)entities[i];				
				bool success = attack(c, target, 0, force);	
				if (target->getHealth() <= 0)
				{
					//c->getRole()->addXP(c, (int)(Role::getXPForLevel(target->getLevel() + 1) / 10));
					entities.erase(entities.begin() + i);		
				}
				if (success)
				{
					result = true;
				}
			}
		}
	}
	else
	{
		int dx = x - c->getX();
		int dy = y - c->getY();
		int range = c->getWeapon()->getRange();
			
		for (int r = 1; r < range; r++)
		{		
			int tx = (c->getX() + (dx * r));
			int ty = (c->getY() + (dy * r));
			
			//int penalty = floor((r / range) * 2);
			int penalty = 0;
			
			for (int i = 0; i < entities.size(); ++i)
			{
				if (entities[i]->getActor() && entities[i]->getX() == tx && entities[i]->getY() == ty)
				{
					Character* target = (Character*)entities[i];
					bool success = attack(c, target, penalty, force);
					if (target->getHealth() <= 0)
					{
						//c->getRole()->addXP(c, (int)(Role::getXPForLevel(target->getRole()->getLevel() + 1) / 10));
						entities.erase(entities.begin() + i);		
					}
					if (success)
					{
						result = true;								
						r = range;
					}
				}
			}	
		
			if (tiles->isSolid(tx,ty))
			{
				r = range;
			}	
							
			if (r < range)
			{
				Projectile* p = new Projectile(this, dx, dy, c->getWeapon()->getName());
				p->moveTo(tx,ty);
				entities.push_back(p);
				draw();
				delay(20);
				entities.pop_back();
			}				
		}
	}
	return result;
}

bool Rad::attack(Character* c, Character* target, int penalty, bool force)
{
	if (target->getFaction() != c->getFaction() || force)
	{
		string result = "";
		int attackRoll = c->getAttackRoll() + penalty;
		int ac = target->getArmorClass();
		if (attackRoll >= ac)
		{
			int damage = c->getDamageRoll(target);
			ostringstream dmg;
			dmg << damage;
			target->setHealth(target->getHealth() - damage);
			if (target->getHealth() <= 0)
			{
				result = c->getName() + " dealt " + dmg.str() + " damage to " + target->getName() + ". ";
				result += c->getName() + " killed " + target->getName() + ".";
				player->setMessage(result);
			}
			else
			{					
				result = c->getName() + " dealt " + dmg.str() + " damage to " + target->getName() + ".";
				player->setMessage(result);
			}
			return true;
		}
		else
		{
			result = c->getName() + " missed " + target->getName() + ".";
			player->setMessage(result);
			return false;
		}
	}
	return false;
}

void Rad::castHPSpellAt(Character* c, int x, int y, int dc, string save, int damage, string s, bool animate)
{
	/*if (x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT)
	{
		return;
	}
	for (int i = 0; i < entities.size(); ++i)
	{
		if (entities[i]->hasStats() && entities[i]->getX() == x && entities[i]->getY() == y)
		{
			Character* target = (Character*)entities[i];
			int savingThrow = 0;
			int damageTaken = damage;
			if (save == "fortitude")
			{
				savingThrow = d(20) + target->getFortitude();
			}
			else if (save == "reflex")
			{
				savingThrow = d(20) + target->getReflex();
			}
			else if (save == "will")
			{
				savingThrow = d(20) + target->getWill();
			}
			else if (save == "will harmless")
			{
				if (target->getRole()->getName() == "Undead")
				{
					savingThrow = d(20) + target->getWill();
					damage = -damage;
				}
				else
				{
					savingThrow = 0;
				}
			}
			string result = "";
			if (savingThrow >= dc)
			{
				damageTaken = floor(damage/2);
				result += target->getName() + " resisted! ";
			}
			if (target->getHealth() - damageTaken > target->getMaxHealth())
			{
				damageTaken = -(target->getMaxHealth() - target->getHealth());
			}
			target->setHealth(target->getHealth() - damageTaken);
			if (damageTaken > 0)
			{
				result += target->getName() + " took " + intToStr(damageTaken) + " damage.";
			}
			else if (damageTaken < 0)
			{
				result += target->getName() + " healed " + intToStr(-damageTaken) + " hit points.";
			}
			else
			{
				result += target->getName() + " was not affected!";
			}
			if (target->getHealth() <= 0)
			{
				result += " " + target->getName() + " was killed.";
				player->setMessage(result);
				c->getRole()->addXP(c, (int)(Role::getXPForLevel(target->getRole()->getLevel() + 1) / 10));
				entities.erase(entities.begin() + i);	
				break;
			}
			player->setMessage(result);
		}
	}
	if (animate)
	{
		Projectile* p = new Projectile(this, x, y, s);
		p->moveTo(x,y);
		entities.push_back(p);
		draw();
		delay(50);
		entities.pop_back();
	}*/
}

void Rad::castRangedHPSpellAt(Character* c, int x, int y, int dx, int dy, int dc, string save, int damage, string s, bool animate)
{
	/*while (!isSolid(x,y))
	{
		if (animate)
		{
			Projectile* p = new Projectile(this, x, y, s);
			p->moveTo(x,y);
			entities.push_back(p);
			draw();
			delay(20);
			entities.pop_back();
		}
		x += dx;
		y += dy;
	}
	castHPSpellAt(c, x, y, dc, save, damage, s, animate);*/
}

void Rad::delay(int ms)
{
	#ifdef ALLOW_DELAYS
		#ifdef WINDOWS_DELAYS
			Sleep(ms);
		#endif
		#ifdef POSIX_DELAYS
			usleep(ms*1000); // usleep takes microseconds
		#endif
	#endif
}

string Rad::intToStr(int i)
{	
	ostringstream convert;
	convert << i;
	return convert.str();
}

bool Rad::goDownStairs()
{
	if (tiles->getTile(player->getCharacter()->getX(), player->getCharacter()->getY())->getName() == "stairs")
	{
		for (int i = entities.size() - 1; i >= 0; --i)
		{
			if (entities[i] != player->getCharacter())
			{
				entities.erase(entities.begin() + i);	
			}
		}
		delete(tiles);
		level++;
		tiles = new TileMap(graphics, this, level);
	
		for (int i = 0; i < 100; ++i)
		{
			/*NPC* npc = tiles->placeNPC(player);
			if (npc != NULL)
			{
				npc->initializeAbilityScores();
				npc->initializeStats();
				npc->initializeSpells();
				entities.push_back(npc);
			}*/
		}
		
		tiles->positionPlayer(player);
		player->centreCamera();
		return true;
	}
	return false;
}
