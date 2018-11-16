#include "Graphics.h"

// Constructors and Destructors //

Graphics::Graphics()
{
	initscr();
	#ifdef ENABLE_COLOURS
	start_color();
	#endif
	initializeColours();
}

Graphics::~Graphics()
{
	endwin();
}

// Functions //

void Graphics::clearScreen()
{
	clear();
}

void Graphics::refreshScreen()
{
	refresh();
}

void Graphics::initializeColours()
{	
	#ifdef ENABLE_COLOURS
	int c = 0;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			init_pair(c, j, i);
			++c;
		}
	}
	#endif
}

bool Graphics::isOnScreen(int x, int y)
{
	if (x < 0)
		return false;
	if (x >= COLS)
		return false;
	if (y < 0)
		return false;
	if (y >= LINES)
		return false;
	return true;
}

void Graphics::moveTo(int x, int y)
{
	if (!isOnScreen(x, y))
		return;
	move(y, x);
}

void Graphics::drawCharacter(char c, int i, int i2)
{
	chtype ch = c;
	#ifdef ENABLE_COLOURS
	attron(COLOR_PAIR (i + i2 * 8));
	#endif
	addch(ch);
	#ifdef ENABLE_COLOURS
	attroff(COLOR_PAIR (i + i2 * 8));
	#endif
}

void Graphics::drawCharacter(int x, int y, char c, int i, int i2)
{
	if (!isOnScreen(x, y))
		return;
	chtype ch = c;
	#ifdef ENABLE_COLOURS
	attron(COLOR_PAIR (i + i2 * 8));
	#endif
	mvaddch(y, x, ch);
	#ifdef ENABLE_COLOURS
	attroff(COLOR_PAIR (i + i2 * 8));
	#endif
}

void Graphics::drawGraphic(Graphic g)
{
	drawCharacter(g.getX(), g.getY(), g.getCharacter(), g.getColour(), g.getBackground());
}

void Graphics::drawGraphicInverted(Graphic g)
{
	drawCharacter(g.getX(), -(g.getY()), g.getCharacter(), g.getColour(), g.getBackground());
}

void Graphics::drawGraphic(Graphic g, int x, int y)
{
	drawCharacter(g.getX() + x, g.getY() + y, g.getCharacter(), g.getColour(), g.getBackground());
}

void Graphics::drawGraphicInverted(Graphic g, int x, int y)
{
	drawCharacter(g.getX() + x, -(g.getY() + y), g.getCharacter(), g.getColour(), g.getBackground());
}

void Graphics::drawGraphicCentred(Graphic g, int x, int y)
{
	drawGraphic(g, round(COLS / 2) + x, round(LINES / 2) + y);
}

void Graphics::drawGraphicInvertedCentred(Graphic g, int x, int y)
{
	drawGraphicInverted(g, round(COLS / 2) + x, -round(LINES / 2) + y);
}