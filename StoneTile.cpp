#include "StoneTile.h"

// Constructors and Destructors //

StoneTile::StoneTile()
{
	graphic = new Graphic(0, 0, ' ', COLOR_WHITE);
}

// Functions //

// Misc

bool StoneTile::isSolid()
{
	return true;
}