#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
#include <curses.h>
#include <cmath>

#include "Entity.h"
#include "Graphic.h"

#define ITEM_ARMOR 0
#define ITEM_WEAPON 1
#define ITEM_MISC 2
#define ITEM_AMULET 3
#define ITEM_POTION 4
#define ITEM_SCROLL 5
#define ITEM_AMMO 6

class Rad;
class Character;

using namespace std;

class Item: public Entity
{
	// Members //
	
	protected:
		int itemType;
		string name;
		int level;
		int value;
		bool identified;
		bool equipped;
		
	// Constructors and Destructors //
	
	public:
		Item(Rad*, int, int, string, int, bool, bool);
		
	// Functions //
		
	public:
		// Getters:
		Actor* getActor();
		int getItemType() const;
		int getLevel() const;
		string getName() const;
		int getValue() const;
		bool getIdentified() const;
		bool getEquipped() const;
		
		// Setters:
		void setName(string);
		void setValue(int);
		
		// Misc:
		void update();
		string itemString();
		bool equip(vector<Item*>);
		bool drop(vector<Item*>);
		bool use(Character*);
};

#endif
