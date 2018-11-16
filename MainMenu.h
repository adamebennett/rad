#ifndef MAINMENU_H
#define MAINMENU_H

#include <string>
#include <vector>

#include "Graphics.h"
#include "miscFunctions.h"

#define MENU_CONTINUE 0
#define MENU_EXIT 1

class Rad;
class Character;

using namespace std;
		
class MainMenu
{
	// Members //
	
	protected:
		Graphics* graphics;
		int selected;
		
	// Constructors and Destructors //
	
	public:
		MainMenu(Graphics*);
		~MainMenu();
		
	// Functions //
	
	public:
		// Misc:
		int showTitle();
		Character* getCharacterInformation(Rad*);
		int showMenu(string, vector<string>, bool);
		
	protected:
		void drawMenu(string, int, vector<string>, bool);
};

#endif