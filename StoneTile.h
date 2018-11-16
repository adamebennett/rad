#ifndef STONETILE_H
#define STONETILE_H

#include <vector>
#include <curses.h>
#include <cmath>

#include "Tile.h"
#include "Graphic.h"

using std::vector;

class StoneTile: public Tile
{		
	// Constructors and Destructors //
	
	public:
		StoneTile();
		
	// Functions //
		
	public:		
		// Misc
		virtual bool isSolid();
};

#endif