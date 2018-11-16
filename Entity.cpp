#include "Entity.h"
#include "Rad.h"

// Constructors and Destructors //

Entity::Entity(Rad* t)
{
	rad = t;
	x = 0;
	y = 0;
}

// Functions //

// Getters:

Graphic Entity::getGraphic() const
{
	graphic->moveTo(x, y);
	return *graphic;
}

int Entity::getX() const
{
	return x;
}

int Entity::getY() const
{
	return y;
}

// Setters:

void Entity::setGraphic(Graphic* g)
{
	graphic = g;
}

void Entity::setX(int i)
{
	x = i;
}

void Entity::setY(int i)
{
	y = i;
}

// Misc:

bool Entity::moveBy(int i1, int i2)
{
	if (!rad->isSolid(x + i1, y + i2))
	{
		x = x + i1;
		y = y + i2;
		return true;
	}
	return false;
}

void Entity::moveTo(int i1, int i2)
{
	x = i1;
	y = i2;
}