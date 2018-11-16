#ifndef ACTOR_H
#define ACTOR_H

#include <curses.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

class Character;

using namespace std;

class Actor
{
	// Members //
		
	// Functions //
	
	public:
		// Getters:
		virtual Character* getCharacter() = 0;
		
		// Misc:
		virtual void control(int) = 0;
};

#endif