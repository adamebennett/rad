#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <ncurses.h>
#include <cmath>

#include "Graphic.h"

#define ENABLE_COLOURS // don't define this for platforms that don't support colours

class Graphics
{
	// Constructors and Destructors //
	
	public:
		Graphics();
		~Graphics();
		
	// Functions //
	
	public:
		void clearScreen();
		void refreshScreen();
		void initializeColours();
		bool isOnScreen(int, int);
		void moveTo(int, int);
		void drawCharacter(char, int, int);
		void drawCharacter(int, int, char, int, int);
		void drawGraphic(Graphic);
		void drawGraphicInverted(Graphic);
		void drawGraphic(Graphic, int, int);
		void drawGraphicInverted(Graphic, int, int);
		void drawGraphicCentred(Graphic, int, int);
		void drawGraphicInvertedCentred(Graphic, int, int);
};

#endif