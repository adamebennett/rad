#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <curses.h>
#include <cmath>

#include "Graphic.h"

using std::vector;

class Rad;
class Actor;

class Entity
{
	// Members //
	
	protected:
		Rad* rad;
		Graphic* graphic;
		int x;
		int y;
		
	// Constructors and Destructors //
	
	public:
		Entity(Rad*);
		
	// Functions //
		
	public:
		// Getters:
		virtual Actor* getActor() = 0;
		Graphic getGraphic() const;
		virtual int getX() const;
		virtual int getY() const;
		
		// Setters:
		void setGraphic(Graphic*);
		void setX(int);
		void setY(int);
		
		// Misc:
		bool moveBy(int, int);
		void moveTo(int, int);
		virtual void update() = 0;
};

#endif