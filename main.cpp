#include <stdlib.h>
#include <curses.h>

#include "Graphics.h"
#include "MainMenu.h"
#include "Rad.h"
#include "Entity.h"
#include "Character.h"

int main()
{
	while (true)
	{
		Graphics graphics;
		MainMenu mainMenu(&graphics);
		int titleSelect = mainMenu.showTitle();
		if (titleSelect == MENU_EXIT)
		{
			return 0;
		}
		Rad rad(&graphics);
		Character* character = mainMenu.getCharacterInformation(&rad);
		rad.initialize(character);
	}
	
	return 0;
}