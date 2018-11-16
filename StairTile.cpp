#include "StairTile.h"

// Constructors and Destructors //

StairTile::StairTile()
{
	graphic = new Graphic(0, 0, '>', COLOR_WHITE);
}

// Functions //

// Misc

bool StairTile::isSolid()
{
	return false;
}

string StairTile::getName()
{
	return "stairs";
}