#ifndef WALLTILE_H
#define WALLTILE_H

#include <vector>
#include <curses.h>
#include <cmath>

#include "Tile.h"
#include "Graphic.h"

using std::vector;

class WallTile: public Tile
{
	// Constructors and Destructors //
	
	public:
		WallTile();
		
	// Functions //
		
	public:
		// Misc
		virtual bool isSolid();
		virtual string getName();
};

#endif