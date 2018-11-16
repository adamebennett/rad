#ifndef SOLIDTILE_H
#define SOLIDTILE_H

#include <vector>
#include <curses.h>
#include <cmath>

#include "Tile.h"
#include "Graphic.h"

using std::vector;

class SolidTile: public Tile
{		
	// Constructors and Destructors //
	
	public:
		SolidTile();
		
	// Functions //
		
	public:		
		// Misc
		virtual bool isSolid();
		virtual string getName();
};

#endif