#include "SolidTile.h"

// Constructors and Destructors //

SolidTile::SolidTile()
{
	graphic = new Graphic(0, 0, ' ', COLOR_WHITE);
}

// Functions //

// Misc

bool SolidTile::isSolid()
{
	return true;
}

string SolidTile::getName()
{
	return "solid";
}