#ifndef PLAYER_H
#define PLAYER_H

#include <curses.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#include "Actor.h"
#include "Character.h"
#include "miscFunctions.h"

class Rad;
class Hud;

using namespace std;

class Player: public Actor
{
	// Members //
	
	private:
		Rad* rad;
		Character* character;
		int cameraX;
		int cameraY;
		vector<string> messageLog;
		
	// Constructors and Destructors //
	
	public:
		Player(Rad*, Character*);
		~Player();
		
	// Functions //
	
	public:
		// Getters:
		Character* getCharacter();
		int getCameraX();
		int getCameraY();
		virtual string getMessage();
		
		// Setters:
		void setCharacter(Character*);
		virtual void setMessage(string);
		
		// Misc:
		void control(int);
		void centreCamera();
		void controlWaiting(int);
		void controlMovement(int);
		void controlAttack(int);
		void controlLog(int);
		void controlInventory(int);
		void controlCharacterSheet(int);
		void chooseDirection(int*, int*, string);
		void showLog();
};

#endif