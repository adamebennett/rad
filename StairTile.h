#ifndef STAIRTILE_H
#define STAIRTILE_H

#include <vector>
#include <curses.h>
#include <cmath>

#include "Tile.h"
#include "Graphic.h"

using std::vector;

class StairTile: public Tile
{
	// Constructors and Destructors //
	
	public:
		StairTile();
		
	// Functions //
		
	public:
		// Misc
		virtual bool isSolid();
		virtual string getName();
};

#endif