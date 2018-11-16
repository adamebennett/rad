#ifndef NPC_H
#define NPC_H

#include <curses.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#include "Actor.h"
#include "Character.h"
#include "miscFunctions.h"

class Rad;

using namespace std;

class NPC: public Actor
{
	// Members //
	
	private:
		Rad* rad;
		Character* character;
		Character* target;
		int busy;
		
	// Constructors and Destructors //
	
	public:
		NPC(Rad*, Character*, int, int, int);
		~NPC();
		
	// Functions //
	
	public:
		// Getters:
		Character* getCharacter();
		Character* getTarget();
		
		// Setters:
		void setCharacter(Character*);
		
		// Misc:
		void control(int);
		void controlWaiting();
		void controlMovement();
		void controlAttack();
		bool adjacentToTarget();
};

#endif