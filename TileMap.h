#ifndef TILEMAP_H
#define TILEMAP_H

#include <string>
#include <vector>
#include <algorithm>
#include <curses.h>
#include <cmath>

#include "Tile.h"
#include "SolidTile.h"
#include "StoneTile.h"
#include "WallTile.h"
#include "StairTile.h"
#include "Graphic.h"
#include "Graphics.h"
#include "Player.h"
#include "NPC.h"

#define MAP_WIDTH 152
#define MAP_HEIGHT 152
#define NUM_ROOMS_X 30
#define NUM_ROOMS_Y 30

class Rad;
class Room;

using namespace std;

class TileMap
{
	// Members //
	
	protected:
		Graphics* graphics;
		Rad* rad;
		Tile* map[MAP_WIDTH][MAP_HEIGHT];
		int level;
		vector<Room*> rooms;
		Room* roomsToLoad[NUM_ROOMS_X][NUM_ROOMS_Y];
		
	// Constructors and Destructors //
	
	public:
		TileMap(Graphics*, Rad*, int);
		~TileMap();
		
	// Functions //
		
	public:
		// Misc:
		void draw(int, int) const;
		void hide();
		Tile* getTile(int, int);
		bool isSolid(int, int);
		void replaceTile(int, int, Tile*);
		bool getVisible(int, int);
		void setVisible(int, int, bool);
		bool getRevealed(int, int);
		void setRevealed(int, int, bool);
		NPC* placeNPC(Character*);
		void positionPlayer(Player*);
		
	protected:
		void initializeMap(int, int);
		void generateRooms(int, int, int, int, int, int, Room*);
		Room* getRoom(int, int, int, int);
		void loadRooms();
		void fillBorder();
		void addStairs();
};

#endif