#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <string>
#include <curses.h>
#include <cmath>

#include "Graphic.h"
#include "Entity.h"

using namespace std;

class Projectile: public Entity
{
		
	// Constructors and Destructors //
	
	public:
		Projectile(Rad*, int, int, string);
		
	// Functions //
		
	public:
		// Getters:		
		virtual Actor* getActor();
		
		// Misc:
		virtual void update();
};

#endif