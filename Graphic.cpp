#include "Graphic.h"

// Constructors and Destructors //

Graphic::Graphic(char c, int i3)
{
	x = 0;
	y = 0;
	character = c;
	colour = i3;
	background = COLOR_BLACK;
}

Graphic::Graphic(char c, int i3, int bg)
{
	x = 0;
	y = 0;
	character = c;
	colour = i3;
	background = bg;
}

Graphic::Graphic(int i1, int i2, char c, int i3)
{
	x = i1;
	y = i2;
	character = c;
	colour = i3;
	background = COLOR_BLACK;
}

Graphic::Graphic(int i1, int i2, char c, int i3, int bg)
{
	x = i1;
	y = i2;
	character = c;
	colour = i3;
	background = bg;
}

Graphic::Graphic(double d1, double d2, char c, int i)
{
	x = round(d1);
	y = round(d2);
	character = c;
	colour = i;
	background = COLOR_BLACK;
}

Graphic::Graphic(double d1, double d2, char c, int i, int bg)
{
	x = round(d1);
	y = round(d2);
	character = c;
	colour = i;
	background = bg;
}

// Functions //

// Getters:

int Graphic::getX()
{
	return x;
}

int Graphic::getY()
{
	return y;
}

char Graphic::getCharacter()
{
	return character;
}

int Graphic::getColour()
{
	return colour;
}

int Graphic::getBackground()
{
	return background;
}

// Setters:

void Graphic::setX(int i)
{
	x = i;
}

void Graphic::setY(int i)
{
	y = i;
}

// Misc:

void Graphic::moveTo(int i1, int i2)
{
	x = i1;
	y = i2;
}

void Graphic::moveTo(double d1, double d2)
{
	x = round(d1);
	y = round(d2);
}