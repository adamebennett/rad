#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include <curses.h>
#include <cmath>

#include "Tile.h"
#include "SolidTile.h"
#include "StoneTile.h"
#include "WallTile.h"

#define ROOM_WIDTH 5
#define ROOM_HEIGHT 5

class Room;

using namespace std;

class Room
{
	// Members //
	
	protected:
		int id;
		string tiles[ROOM_HEIGHT];
		int northID;
		int eastID;
		int southID;
		int westID;
		
	// Constructors and Destructors //
	
	public:
		Room(int);
		
	// Functions //
	
	public:
		// Getters:
		int getID();
		int getNorthID();
		int getEastID();
		int getSouthID();
		int getWestID();
		char getTile(int, int);
	
	protected:
		// Misc:
		void copyRoom(string[]);
		void initRoom0();
		void initRoom1();
		void initRoom2();
		void initRoom3();
		void initRoom4();
		void initRoom5();
		void initRoom6();
		void initRoom7();
		void initRoom8();
		void initRoom9();
		void initRoom10();
		void initRoom11();
		void initRoom12();
		void initRoom13();
		void initRoom14();
		void initRoom15();
		void initRoom16();
		void initRoom17();
		void initRoom18();
		void initRoom19();
		void initRoom20();
		void initRoom21();
		void initRoom22();
		void initRoom23();
		void initRoom24();
		void initRoom25();
		void initRoom26();
		void initRoom27();
		void initRoom28();
		void initRoom29();
		void initRoom30();
		void initRoom31();
		void initRoom32();
		void initRoom33();
		void initRoom34();
		void initRoom35();
		void initRoom36();
		void initRoom37();
		void initRoom38();
		void initRoom39();
		void initRoom40();
		void initRoom41();
		void initRoom42();
		void initRoom43();
		void initRoom44();
		void initRoom45();
		void initRoom46();
		void initRoom47();
		void initRoom48();
		void initRoom49();
		void initRoom50();
		void initRoom51();
};

#endif