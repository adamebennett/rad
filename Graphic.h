#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <cmath>
#include <ncurses.h>

class Graphic
{
	// Members //
	
	protected:
		int x;
		int y;
		char character;
		int colour;		
		int background;		

	// Constructors and Destructors //
	
	public:
		Graphic(char, int);
		Graphic(char, int, int);
		Graphic(int, int, char, int);
		Graphic(int, int, char, int, int);
		Graphic(double, double, char, int);
		Graphic(double, double, char, int, int);
		
	// Functions //
	
	public:
		// Getters:
		int getX();
		int getY();
		char getCharacter();
		int getColour();
		int getBackground();
		
		// Setters:
		void setX(int);
		void setY(int);
		
		// Misc:
		void moveTo(int, int);
		void moveTo(double, double);

};

#endif