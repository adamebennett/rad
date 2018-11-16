#ifndef ARMOR_H
#define ARMOR_H

#include <string>
#include <vector>
#include <curses.h>
#include <cmath>

#include "Entity.h"
#include "Item.h"
#include "Graphic.h"

class Rad;
class Character;

using namespace std;

class Armor: public Item
{
	// Members //
	
	protected:
		int armorValue;
		int maxDex;
		int armorCheck;
		int failureChance;
		
	// Constructors and Destructors //
	
	public:
		Armor(Rad*, int, int, string, int, bool, bool, int, int, int, int);
		
	// Functions //
		
	public:
		// Getters:
		int getArmorValue();
		int getMaxDex();
		int getArmorCheck();
		int getFailureChance();
};

#endif
