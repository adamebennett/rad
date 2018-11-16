#ifndef RAD_H
#define RAD_H

#include <string>
#include <vector>
#include <algorithm>
#include <time.h>

#include "Graphics.h"
#include "Hud.h"
#include "Entity.h"
#include "TileMap.h"
#include "miscFunctions.h"

#define DRAW_DIST 60
#define PI 3.14159265358979323846

#define ALLOW_DELAYS
//#define WINDOWS_DELAYS
#define POSIX_DELAYS

class Graphics;
class Player;
class Character;

using namespace std;

bool compareEntities(const Entity* e1, const Entity* e2);
		
class Rad
{	
	// Members //
	
	protected:
		Graphics* graphics;
		Hud* hud;
		Player* player;
		vector<Entity*> entities;
		TileMap* tiles;
		char inChar;
		int cameraX;
		int cameraY;
		int turns;
		int level;
		
	// Constructors and Destructors //
	
	public:
		Rad(Graphics*);
		~Rad();
		
	// Functions //
	
	public:
		// Getters:
		vector<Entity*>* getEntities();
		int getTurns();
		Player* getPlayer();
		
		// Misc:
		void initialize(Character*);
		int d(int);
		int numD(int, int);
		int calculateModifier(int);
		void mainLoop();
		void turnCompleted(int);
		void revealTiles();
		void draw();
		void centreCamera();
		void controlCamera();
		void drawEntities(vector<Entity*>&);
		bool isSolid(int, int);
		bool isMapSolid(int, int);
		void addEntity(Entity*, vector<Entity*>&);
		void removeEntity(Entity*, vector<Entity*>&);
		int showMenu(vector<string>, bool);
		bool canSee(Character*, Entity*);
		bool attackAt(int, int, Character*, bool);
		void castHPSpellAt(Character*, int, int, int, string, int, string, bool);
		void castRangedHPSpellAt(Character*, int, int, int, int, int, string, int, string, bool);
		void delay(int);
		string intToStr(int);
		bool goDownStairs();
		
	private:	
		bool attack(Character*, Character*, int, bool);
};

#endif
