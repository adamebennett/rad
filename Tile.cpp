#include "Tile.h"

// Constructors and Destructors //

Tile::Tile()
{
	graphic = new Graphic(0, 0, '.', COLOR_WHITE);
	visible = false;
	revealed = false;
}

// Functions //

// Getters:

Graphic Tile::getGraphic() const
{
	graphic->moveTo(0, 0);
	return *graphic;
}

bool Tile::getVisible()
{
	return visible;
}

bool Tile::getRevealed()
{
	return revealed;
}

// Setters:

void Tile::setVisible(bool b)
{
	visible = b;
}

void Tile::setRevealed(bool b)
{
	revealed = b;
}

// Misc

bool Tile::isSolid()
{
	return false;
}

string Tile::getName()
{
	return "floor";
}