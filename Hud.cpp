#include "Hud.h"
#include "Rad.h"
#include "Player.h"

// Constructors and Destructors //

Hud::Hud(Rad* t, Graphics* g, Player* p, char c)
{
	rad = t;
	graphics = g;
	player = p;
	topHeight = 3;
	bottomHeight = 3;
	lineChar = c;
}

Hud::~Hud()
{
}

// Functions //

void Hud::draw()
{
	clear();
	drawLines();
	drawInformation();
}

int Hud::showMenu(vector<string> v, bool isMenu)
{
	int selected = 0;
	graphics->clearScreen();
	drawMenu(selected, v, isMenu);
	draw();
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
		drawMenu(selected, v, isMenu);
		draw();
	}
	return selected;
}

void Hud::clear()
{
	for (int i = 0; i < topHeight; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			graphics->drawCharacter(j, i, ' ', COLOR_BLACK, COLOR_BLACK);
		}
	}
	for (int i = LINES - bottomHeight; i < LINES; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			graphics->drawCharacter(j, i, ' ', COLOR_BLACK, COLOR_BLACK);
		}
	}
}

void Hud::drawLines()
{
	for (int i = 0; i < COLS; i++)
	{
		graphics->drawCharacter(i, topHeight - 1, lineChar, COLOR_WHITE, COLOR_BLACK);
	}
	for (int i = 0; i < COLS; i++)
	{
		graphics->drawCharacter(i, LINES - bottomHeight, lineChar, COLOR_WHITE, COLOR_BLACK);
	}
}

void Hud::drawInformation()
{
	drawPlayerInformation();
	drawOutputInformation();
	drawInputInformation();
}

string Hud::doubleToString(double d, int i)
{	
	stringstream fixedPointStream;
	fixedPointStream.setf(ios_base::fixed);
	fixedPointStream << d;
	
	if (fixedPointStream.str().length() <= i)
		return fixedPointStream.str();
	
	stringstream scientificStream2;
	scientificStream2.setf(ios_base::scientific);
	scientificStream2.precision(2);
	scientificStream2 << d;
	
	if (scientificStream2.str().length() <= i)
		return scientificStream2.str();
	
	stringstream scientificStream1;
	scientificStream1.setf(ios_base::scientific);
	scientificStream1.precision(1);
	scientificStream1 << d;
	
	if (scientificStream1.str().length() <= i)
		return scientificStream1.str();
	
	stringstream intStream;
	intStream << (int)round(d);
	
	if (intStream.str().length() <= i)
		return intStream.str();
		
	return string("?");
}

string Hud::readOut(string s, double d, int i)
{
	return s + doubleToString(d, i - s.length());
}

void Hud::drawPlayerInformation()
{
	if (player->getCharacter() == NULL) {
		return;
	}

	// First line
	int fields = 0;
	int fieldWidth = 7;
	
	graphics->moveTo(fields * fieldWidth + fields, 0);
	addstr(player->getCharacter()->getName().c_str());
	
	fields++;
	
	graphics->moveTo(fields * fieldWidth + fields, 0);
	addstr(readOut(string("LVL:"), player->getCharacter()->calculateLevel(), fieldWidth).c_str());
	
	fields++;
	
	graphics->moveTo(fields * fieldWidth + fields, 0);
	addstr(player->getCharacter()->getRole().c_str());
	
	fields++;
	fields++; // gap to make things more readable
	
	graphics->moveTo(fields * fieldWidth + fields, 0);
	addstr(readOut(string("STR:"), player->getCharacter()->getStrength(), fieldWidth).c_str());
	
	fields++;
	
	graphics->moveTo(fields * fieldWidth + fields, 0);
	addstr(readOut(string("DEX:"), player->getCharacter()->getDexterity(), fieldWidth).c_str());
	
	fields++;
	
	graphics->moveTo(fields * fieldWidth + fields, 0);
	addstr(readOut(string("CON:"), player->getCharacter()->getConstitution(), fieldWidth).c_str());
	
	fields++;
	
	graphics->moveTo(fields * fieldWidth + fields, 0);
	addstr(readOut(string("INT:"), player->getCharacter()->getIntelligence(), fieldWidth).c_str());
	
	fields++;
	
	graphics->moveTo(fields * fieldWidth + fields, 0);
	addstr(readOut(string("WIS:"), player->getCharacter()->getWisdom(), fieldWidth).c_str());
	
	fields++;
	
	graphics->moveTo(fields * fieldWidth + fields, 0);
	addstr(readOut(string("CHA:"), player->getCharacter()->getCharisma(), fieldWidth).c_str());
		
	// Second line
	fields = 0;
	fieldWidth = 7;
	
	graphics->moveTo(fields * fieldWidth + fields, 1);
	addstr(readOut(string("HP:"), player->getCharacter()->getHealth(), fieldWidth).c_str());
	
	fields++;
	
	graphics->moveTo(fields * fieldWidth + fields, 1);
	addstr(readOut(string("EP:"), player->getCharacter()->getEnergy(), fieldWidth).c_str());
	
	fields++;
	
	/*if (player->getRole() != NULL)
	{
		graphics->moveTo(fields * fieldWidth + fields, 1);
		addstr(readOut(string("BAB:"), player->getBAB(), fieldWidth).c_str());
	}
	
	fields++;
	
	if (player->getRole() != NULL)
	{
		graphics->moveTo(fields * fieldWidth + fields, 1);
		addstr(readOut(string("CMB:"), player->getCMB(), fieldWidth).c_str());
	}
	
	fields++;
	
	if (player->getRole() != NULL)
	{
		graphics->moveTo(fields * fieldWidth + fields, 1);
		addstr(readOut(string("CMD:"), player->getCMD(), fieldWidth).c_str());
	}
	
	fields++;
	
	graphics->moveTo(fields * fieldWidth + fields, 1);
	addstr(readOut(string("AC:"), player->getArmorClass(), fieldWidth).c_str());
	
	fields++;
	
	if (player->getRole() != NULL)
	{
		graphics->moveTo(fields * fieldWidth + fields, 1);
		addstr(readOut(string("FORT:"), player->getFortitude(), fieldWidth).c_str());
	}
	
	fields++;
	
	if (player->getRole() != NULL)
	{
		graphics->moveTo(fields * fieldWidth + fields, 1);
		addstr(readOut(string("REF:"), player->getReflex(), fieldWidth).c_str());
	}
	
	fields++;
	
	if (player->getRole() != NULL)
	{
		graphics->moveTo(fields * fieldWidth + fields, 1);
		addstr(readOut(string("WILL:"), player->getWill(), fieldWidth).c_str());
	}*/
}

void Hud::drawOutputInformation()
{
	string delimiter = string(" ");

	// Output information:
	graphics->moveTo(0, LINES - 1 - 1);
	stringstream outputStream;
	outputStream.setf(ios_base::left);
	outputStream.fill(' ');
	
	outputStream << player->getMessage();
	
	addstr(outputStream.str().c_str());
}

void Hud::drawInputInformation()
{
	string delimiter = string(" ");

	// Input information:
	graphics->moveTo(0, LINES - 1);
	stringstream inputStream;
	inputStream.setf(ios_base::left);
	inputStream.fill(' ');
	
	inputStream << ">";
	
	addstr(inputStream.str().c_str());
}

void Hud::drawMenu(int selected, vector<string> v, bool showSelection)
{
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
}
