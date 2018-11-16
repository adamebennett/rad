#include "MainMenu.h"
#include "Rad.h"
#include "Graphics.h"
#include "Character.h"
#include "Soldier.h"
#include "Hacker.h"
#include "Psychic.h"

// Constructors and Destructors //

MainMenu::MainMenu(Graphics* g)
{
	graphics = g;
	selected = 0;
}

MainMenu::~MainMenu()
{
}

// Functions //

// Misc

int MainMenu::showTitle()
{	
	char inChar = ' ';
	while (true)
	{
		graphics->clearScreen();
		graphics->moveTo(0, 0);
		addstr("RAD");
		graphics->moveTo(0, 1);
		addstr("===");
		graphics->moveTo(0, 3 + selected);
		addstr("> ");
		graphics->moveTo(10, 3 + selected);
		addstr(" <");
		graphics->moveTo(2, 3);
		addstr("Continue");
		graphics->moveTo(2, 4);
		addstr("Exit");
		graphics->moveTo(0, 3 + selected);
		inChar = getch();
		if (inChar == 'w')
		{
			if (selected > 0)
			{
				selected--;
			}
		}
		else if (inChar == 's')
		{
			if (selected < 1)
			{
				selected++;
			}
		}
		else if (inChar == '\n')
		{
			return selected;
		}
	}
	return MENU_EXIT;
}

Character* MainMenu::getCharacterInformation(Rad* rad)
{
	Character* character;
	graphics->clearScreen();
	graphics->moveTo(0, 0);
	addstr("What is your name?");
	graphics->moveTo(0, 1);
	char n[7];
	getnstr(n, 7);
	graphics->clearScreen();
	graphics->moveTo(0, 0);
	addstr("Select a role:");
	vector<string> roles;
	roles.push_back("Soldier");
	roles.push_back("Hacker");
	roles.push_back("Psychic");
	int roleIndex = -1;
	string prompt = string("Select a role:");
	while (roleIndex == -1)
	{
		roleIndex = showMenu(prompt, roles, true);
	}
	if (roles[roleIndex] == "Psychic")
	{
		character = new Psychic(rad, rad->getPlayer());
	}
	else if (roles[roleIndex] == "Hacker")
	{
		character = new Hacker(rad, rad->getPlayer());
	}
	else if (roles[roleIndex] == "Soldier")
	{
		character = new Soldier(rad, rad->getPlayer());
	}
	character->setName(string(n));
	character->initializeAbilityScores();
	character->initializeStats();
	character->initializeItems();
	character->initializeSpells();
	return character;
}

int MainMenu::showMenu(string prompt, vector<string> v, bool isMenu)
{
	int selected = 0;
	graphics->clearScreen();
	drawMenu(prompt, selected, v, isMenu);
	char inChar = ' ';
	while (true)
	{		
		inChar = getch();
		if (inChar == 'w' && selected > 0)
		{
			--selected;
		}
		if (inChar == 's' && selected < v.size() - 1)
		{
			++selected;
		}
		if (inChar == '\n')
		{
			break;
		}
		if (inChar == 27 || inChar == 8)
		{
			return -1;
		}
		graphics->clearScreen();
		drawMenu(prompt, selected, v, isMenu);
	}
	return selected;
}

void MainMenu::drawMenu(string prompt, int selected, vector<string> v, bool showSelection)
{
	graphics->clearScreen();
	graphics->moveTo(0, 0);
	addstr(prompt.c_str());
	int topHeight = 1;
	int bottomHeight = 1;
	if (selected != 0)
	{
		graphics->drawCharacter(0, topHeight, '^', COLOR_WHITE, COLOR_BLACK);
	}
	if (selected < v.size() - 1)
	{
		graphics->drawCharacter(0, LINES - bottomHeight - 1, 'v', COLOR_WHITE, COLOR_BLACK);
	}
	for (int i = selected; i < selected + (LINES - topHeight - bottomHeight - 2); i++)
	{
		if (i < v.size())
		{
			graphics->moveTo(0, topHeight + 1 + (i - selected));
			if (showSelection)
			{
				if (i == selected)
				{
					addstr("> ");
				}
				else
				{
					addstr("  ");
				}
			}
			addstr(v[i].c_str());
			if (showSelection)
			{
				if (i == selected)
				{
					addstr(" <");
				}
			}
		}
	}
	graphics->moveTo(0, 2);
}
