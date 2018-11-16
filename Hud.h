#ifndef HUD_H
#define HUD_H

#include <sstream>
#include <curses.h>

#include "Graphics.h"
#include "Character.h"

class Rad;
class Player;

using namespace std;

class Hud
{	
	// Members //
	
	protected:
		Rad* rad;
		Graphics* graphics;
		Player* player;
		int topHeight;
		int bottomHeight;
		char lineChar;
		
	// Constructors and Destructors
	
	public:
		Hud(Rad*, Graphics*, Player*, char);
		~Hud();

	// Functions //
	
	public:
		void draw();
		int showMenu(vector<string>, bool);
		
	protected:
		void clear();
		void drawLines();
		void drawInformation();
		string doubleToString(double, int);
		string readOut(string, double, int);
		void drawPlayerInformation();
		void drawOutputInformation();
		void drawInputInformation();
		void drawMenu(int, vector<string>, bool);
};

#endif