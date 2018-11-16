#ifndef CHARACTER_H
#define CHARACTER_H

#include <curses.h>
#include <string>
#include <cmath>

#include "Entity.h"
#include "miscFunctions.h"

#define SIZE_HUGE -2
#define SIZE_LARGE -1
#define SIZE_MEDIUM 0
#define SIZE_SMALL 1
#define SIZE_TINY 2

#define ACTION_FREE 0
#define ACTION_WAIT 1
#define ACTION_MOVE 1
#define ACTION_ATTACK 1
#define ACTION_CAST 1
#define ACTION_EQUIP_ITEM 1
#define ACTION_EQUIP_ARMOR 10
#define ACTION_USE_ITEM 1
#define ACTION_LEARN_SPELL 10

class Rad;
class Actor;
class Item;
class Spell;
class Weapon;
class Controller;

using namespace std;

class Character: public Entity
{
	// Members //
	
	protected:		
		string name;
		Actor* actor;		
		int faction;		
		int xp;		
		int strength;
		int constitution;
		int dexterity;
		int intelligence;
		int wisdom;
		int charisma;		
		int size;
		int health;
		int maxHealth;
		int energy;		
		vector<Item*> items;
		vector<Spell*> spells;
		
		string message;
		
	// Constructors and Destructors //
	
	public:
		Character(Rad*, Actor*);
		~Character();
		
	// Functions //
	
	// Getters
		string getName();
		virtual string getRole() = 0;
		Actor* getActor();
		int getFaction();
		int getXP();
		int getStrength();
		int getDexterity();
		int getConstitution();
		int getIntelligence();
		int getWisdom();
		int getCharisma();
		virtual int getBAB() = 0;
		virtual int getHitDie() = 0;
		virtual int getFortitude() = 0;
		virtual int getReflex() = 0;
		virtual int getWill() = 0;
		virtual string getMainAbility1() = 0;
		virtual string getMainAbility2() = 0;
		virtual string getMainAbility3() = 0;
		int getSize();
		int getHealth();
		int getMaxHealth();
		int getEnergy();
		virtual int getMaxEnergy();
		int getCMB();
		int getCMD();
		int getArmorClass();
		int getArmorCheck();
		int getSpellFailure();
		virtual int getAttackBonus();
		int getAttackRoll();
		virtual int getDamageRoll(Character*);
		Weapon* getWeapon();
		vector<Item*> getItems();
		virtual string getMessage();
		
	// Setters
		void setName(string);
		void setFaction(int);
		void setActor(Actor*);
		void setXP(int);
		void setHealth(int);
		void setEnergy(int);
		virtual void setMessage(string);
	
	// Misc
		void update();
		int calculateLevel();
		void restore();
		bool ranged();
		bool useWeapon();
		void initializeAbilityScores();
		void initializeStats();
		virtual void initializeItems();
		void initializeSpells();
		void addItem(Item*);
		void addSpell(Spell*);
		bool learnSpell(Spell*);
		void showCharacterSheet();
		void increaseLevel();
};

#endif
