#include "WallTile.h"

// Constructors and Destructors //

WallTile::WallTile()
{
	graphic = new Graphic(0, 0, '#', COLOR_WHITE);
}

// Functions //

// Misc

bool WallTile::isSolid()
{
	return true;
}

string WallTile::getName()
{
	return "wall";
}