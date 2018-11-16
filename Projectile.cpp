#include "Projectile.h"
#include "Rad.h"

// Constructors and Destructors //
	
Projectile::Projectile(Rad* t, int dx, int dy, string s)
	:Entity(t)
{
	if (dx == 0)
	{
		graphic = new Graphic('|', COLOR_WHITE);
	}
	else if (dy == 0)
	{
		graphic = new Graphic('-', COLOR_WHITE);
	}
	else if (dx == dy)
	{
		graphic = new Graphic('/', COLOR_WHITE);
	}
	else
	{
		graphic = new Graphic('\\', COLOR_WHITE);
	}
}
		
// Functions //

Actor* Projectile::getActor()
{
	return NULL;
}
		
void Projectile::update()
{
}
