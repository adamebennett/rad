#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <vector>
#include <curses.h>
#include <cmath>

#include "Entity.h"
#include "Item.h"
#include "Graphic.h"

#define AMMO_NONE 0
#define AMMO_BULLET 1
#define AMMO_BATTERY 2

#define DAMAGE_UNDEFINED 0
#define DAMAGE_PHYSICAL 1
#define DAMAGE_FIRE 2

class Rad;
class Character;

using namespace std;

class Weapon: public Item
{
	// Members //
	
	protected:
		bool ranged;
		int range;
		int numDice;
		int damage;
		int damageType;
		int ammoType;
		
	// Constructors and Destructors //
	
	public:
		Weapon(Rad*, int, int, string, int, bool, bool, bool, int, int, int, int, int);
		
	// Functions //
		
	public:
		// Getters:
		bool getRanged();
		int getRange();
		int getNumDice();
		int getDamage();
		int getDamageType();
		int getAmmoType();
		
		// Misc:
		int rollDamage();
};

#endif
