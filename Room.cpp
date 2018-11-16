#include "Room.h"

// Constructors and Destructors //

Room::Room(int i)
{
	id = i;
	northID = 0;
	eastID = 0;
	southID = 0;
	westID = 0;
	if (id == 0)
	{
		initRoom0();		
	}
	else if (id == 1)
	{
		initRoom1();		
	}
	else if (id == 2)
	{
		initRoom2();		
	}
	else if (id == 3)
	{
		initRoom3();		
	}
	else if (id == 4)
	{
		initRoom4();		
	}
	else if (id == 5)
	{
		initRoom5();		
	}
	else if (id == 6)
	{
		initRoom6();		
	}
	else if (id == 7)
	{
		initRoom7();		
	}
	else if (id == 8)
	{
		initRoom8();		
	}
	else if (id == 9)
	{
		initRoom9();		
	}
	else if (id == 10)
	{
		initRoom10();		
	}
	else if (id == 11)
	{
		initRoom11();		
	}
	else if (id == 12)
	{
		initRoom12();		
	}
	else if (id == 13)
	{
		initRoom13();		
	}
	else if (id == 14)
	{
		initRoom14();		
	}
	else if (id == 15)
	{
		initRoom15();		
	}
	else if (id == 16)
	{
		initRoom16();		
	}
	else if (id == 17)
	{
		initRoom17();		
	}
	else if (id == 18)
	{
		initRoom18();		
	}
	else if (id == 19)
	{
		initRoom19();		
	}
	else if (id == 20)
	{
		initRoom20();		
	}
	else if (id == 21)
	{
		initRoom21();		
	}
	else if (id == 22)
	{
		initRoom22();		
	}
	else if (id == 23)
	{
		initRoom23();		
	}
	else if (id == 24)
	{
		initRoom24();		
	}
	else if (id == 25)
	{
		initRoom25();		
	}
	else if (id == 26)
	{
		initRoom26();		
	}
	else if (id == 27)
	{
		initRoom27();		
	}
	else if (id == 28)
	{
		initRoom28();		
	}
	else if (id == 29)
	{
		initRoom29();		
	}
	else if (id == 30)
	{
		initRoom30();		
	}
	else if (id == 31)
	{
		initRoom31();		
	}
	else if (id == 32)
	{
		initRoom32();		
	}
	else if (id == 33)
	{
		initRoom33();		
	}
	else if (id == 34)
	{
		initRoom34();		
	}
	else if (id == 35)
	{
		initRoom35();		
	}
	else if (id == 36)
	{
		initRoom36();		
	}
	else if (id == 37)
	{
		initRoom37();		
	}
	else if (id == 38)
	{
		initRoom38();		
	}
	else if (id == 39)
	{
		initRoom39();		
	}
	else if (id == 40)
	{
		initRoom40();		
	}
	else if (id == 41)
	{
		initRoom41();		
	}
	else if (id == 42)
	{
		initRoom42();		
	}
	else if (id == 43)
	{
		initRoom43();		
	}
	else if (id == 44)
	{
		initRoom44();		
	}
	else if (id == 45)
	{
		initRoom45();		
	}
	else if (id == 46)
	{
		initRoom46();		
	}
	else if (id == 47)
	{
		initRoom47();		
	}
	else if (id == 48)
	{
		initRoom48();		
	}
	else if (id == 49)
	{
		initRoom49();		
	}
	else if (id == 50)
	{
		initRoom50();		
	}
	else if (id == 51)
	{
		initRoom50();		
	}
}

// Functions //

// Getters:

int Room::getID()
{
	return id;
}

int Room::getNorthID()
{
	return northID;
}

int Room::getEastID()
{
	return eastID;
}

int Room::getSouthID()
{
	return southID;
}

int Room::getWestID()
{
	return westID;
}

char Room::getTile(int x, int y)
{
	return tiles[(ROOM_HEIGHT - 1) - y][x];
}

// Misc:

void Room::copyRoom(string original[ROOM_HEIGHT])
{
	for (int i = 0; i < ROOM_HEIGHT; ++i)
	{
		tiles[i] = original[i];
	}
}

void Room::initRoom0()
{
	northID = 0;
	eastID = 0;
	southID = 0;
	westID = 0;
	string newTiles[ROOM_HEIGHT] = {
		"     ",
		"     ",
		"     ",
		"     ",
		"     "
	};
	copyRoom(newTiles);
}

void Room::initRoom1()
{
	northID = 0;
	eastID = 0;
	southID = 0;
	westID = 0;
	string newTiles[ROOM_HEIGHT] = {
		"#####",
		"#####",
		"#####",
		"#####",
		"#####"
	};
	copyRoom(newTiles);
}

void Room::initRoom2()
{
	northID = 2;
	eastID = 2;
	southID = 2;
	westID = 2;
	string newTiles[ROOM_HEIGHT] = {
		".....",
		".....",
		".....",
		".....",
		"....."
	};
	copyRoom(newTiles);
}

void Room::initRoom3()
{
	northID = 0;
	eastID = 3;
	southID = 2;
	westID = 3;
	string newTiles[ROOM_HEIGHT] = {
		"#####",
		".....",
		".....",
		".....",
		"....."
	};
	copyRoom(newTiles);
}

void Room::initRoom4()
{
	northID = 4;
	eastID = 0;
	southID = 4;
	westID = 2;
	string newTiles[ROOM_HEIGHT] = {
		"....#",
		"....#",
		"....#",
		"....#",
		"....#"
	};
	copyRoom(newTiles);
}

void Room::initRoom5()
{
	northID = 2;
	eastID = 4;
	southID = 0;
	westID = 4;
	string newTiles[ROOM_HEIGHT] = {
		".....",
		".....",
		".....",
		".....",
		"#####"
	};
	copyRoom(newTiles);
}

void Room::initRoom6()
{
	northID = 3;
	eastID = 2;
	southID = 3;
	westID = 0;
	string newTiles[ROOM_HEIGHT] = {
		"#....",
		"#....",
		"#....",
		"#....",
		"#...."
	};
	copyRoom(newTiles);
}

void Room::initRoom7()
{
	northID = 1;
	eastID = 3;
	southID = 2;
	westID = 3;
	string newTiles[ROOM_HEIGHT] = {
		"##.##",
		".....",
		".....",
		".....",
		"....."
	};
	copyRoom(newTiles);
}

void Room::initRoom8()
{
	northID = 4;
	eastID = 1;
	southID = 4;
	westID = 2;
	string newTiles[ROOM_HEIGHT] = {
		"....#",
		"....#",
		".....",
		"....#",
		"....#"
	};
	copyRoom(newTiles);
}

void Room::initRoom9()
{
	northID = 2;
	eastID = 4;
	southID = 1;
	westID = 4;
	string newTiles[ROOM_HEIGHT] = {
		".....",
		".....",
		".....",
		".....",
		"##.##"
	};
	copyRoom(newTiles);
}

void Room::initRoom10()
{
	northID = 3;
	eastID = 2;
	southID = 3;
	westID = 1;
	string newTiles[ROOM_HEIGHT] = {
		"#....",
		"#....",
		".....",
		"#....",
		"#...."
	};
	copyRoom(newTiles);
}

void Room::initRoom11()
{
	northID = 0;
	eastID = 0;
	southID = 4;
	westID = 3;
	string newTiles[ROOM_HEIGHT] = {
		"#####",
		"....#",
		"....#",
		"....#",
		"....#"
	};
	copyRoom(newTiles);
}

void Room::initRoom12()
{
	northID = 4;
	eastID = 0;
	southID = 0;
	westID = 4;
	string newTiles[ROOM_HEIGHT] = {
		"....#",
		"....#",
		"....#",
		"....#",
		"#####"
	};
	copyRoom(newTiles);
}

void Room::initRoom13()
{
	northID = 3;
	eastID = 4;
	southID = 0;
	westID = 0;
	string newTiles[ROOM_HEIGHT] = {
		"#....",
		"#....",
		"#....",
		"#....",
		"#####"
	};
	copyRoom(newTiles);
}

void Room::initRoom14()
{
	northID = 0;
	eastID = 3;
	southID = 3;
	westID = 0;
	string newTiles[ROOM_HEIGHT] = {
		"#####",
		"#....",
		"#....",
		"#....",
		"#...."
	};
	copyRoom(newTiles);
}

void Room::initRoom15()
{
	northID = 3;
	eastID = 2;
	southID = 2;
	westID = 3;
	string newTiles[ROOM_HEIGHT] = {
		"#....",
		".....",
		".....",
		".....",
		"....."
	};
	copyRoom(newTiles);
}

void Room::initRoom16()
{
	northID = 4;
	eastID = 3;
	southID = 2;
	westID = 2;
	string newTiles[ROOM_HEIGHT] = {
		"....#",
		".....",
		".....",
		".....",
		"....."
	};
	copyRoom(newTiles);
}

void Room::initRoom17()
{
	northID = 2;
	eastID = 4;
	southID = 4;
	westID = 2;
	string newTiles[ROOM_HEIGHT] = {
		".....",
		".....",
		".....",
		".....",
		"....#"
	};
	copyRoom(newTiles);
}

void Room::initRoom18()
{
	northID = 2;
	eastID = 2;
	southID = 3;
	westID = 4;
	string newTiles[ROOM_HEIGHT] = {
		".....",
		".....",
		".....",
		".....",
		"#...."
	};
	copyRoom(newTiles);
}

void Room::initRoom19()
{
	northID = 0;
	eastID = 1;
	southID = 0;
	westID = 1;
	string newTiles[ROOM_HEIGHT] = {
		"     ",
		"     ",
		".....",
		"     ",
		"     "
	};
	copyRoom(newTiles);
}

void Room::initRoom20()
{
	northID = 1;
	eastID = 0;
	southID = 1;
	westID = 0;
	string newTiles[ROOM_HEIGHT] = {
		"  .  ",
		"  .  ",
		"  .  ",
		"  .  ",
		"  .  "
	};
	copyRoom(newTiles);
}

void Room::initRoom21()
{
	northID = 1;
	eastID = 1;
	southID = 1;
	westID = 1;
	string newTiles[ROOM_HEIGHT] = {
		"  .  ",
		"  .  ",
		".....",
		"  .  ",
		"  .  "
	};
	copyRoom(newTiles);
}

void Room::initRoom22()
{
	northID = 1;
	eastID = 1;
	southID = 0;
	westID = 1;
	string newTiles[ROOM_HEIGHT] = {
		"  .  ",
		"  .  ",
		".....",
		"     ",
		"     "
	};
	copyRoom(newTiles);
}

void Room::initRoom23()
{
	northID = 1;
	eastID = 1;
	southID = 1;
	westID = 0;
	string newTiles[ROOM_HEIGHT] = {
		"  .  ",
		"  .  ",
		"  ...",
		"  .  ",
		"  .  "
	};
	copyRoom(newTiles);
}

void Room::initRoom24()
{
	northID = 0;
	eastID = 1;
	southID = 1;
	westID = 1;
	string newTiles[ROOM_HEIGHT] = {
		"     ",
		"     ",
		".....",
		"  .  ",
		"  .  "
	};
	copyRoom(newTiles);
}

void Room::initRoom25()
{
	northID = 1;
	eastID = 0;
	southID = 1;
	westID = 1;
	string newTiles[ROOM_HEIGHT] = {
		"  .  ",
		"  .  ",
		"...  ",
		"  .  ",
		"  .  "
	};
	copyRoom(newTiles);
}

void Room::initRoom26()
{
	northID = 1;
	eastID = 1;
	southID = 0;
	westID = 0;
	string newTiles[ROOM_HEIGHT] = {
		"  .  ",
		"  .  ",
		"  ...",
		"     ",
		"     "
	};
	copyRoom(newTiles);
}

void Room::initRoom27()
{
	northID = 0;
	eastID = 1;
	southID = 1;
	westID = 0;
	string newTiles[ROOM_HEIGHT] = {
		"     ",
		"     ",
		"  ...",
		"  .  ",
		"  .  "
	};
	copyRoom(newTiles);
}

void Room::initRoom28()
{
	northID = 0;
	eastID = 0;
	southID = 1;
	westID = 1;
	string newTiles[ROOM_HEIGHT] = {
		"     ",
		"     ",
		"...  ",
		"  .  ",
		"  .  "
	};
	copyRoom(newTiles);
}

void Room::initRoom29()
{
	northID = 1;
	eastID = 0;
	southID = 0;
	westID = 1;
	string newTiles[ROOM_HEIGHT] = {
		"  .  ",
		"  .  ",
		"...  ",
		"     ",
		"     "
	};
	copyRoom(newTiles);
}

void Room::initRoom30()
{
	northID = 1;
	eastID = 0;
	southID = 4;
	westID = 3;
	string newTiles[ROOM_HEIGHT] = {
		"##.##",
		"....#",
		"....#",
		"....#",
		"....#"
	};
	copyRoom(newTiles);
}

void Room::initRoom31()
{
	northID = 4;
	eastID = 1;
	southID = 0;
	westID = 4;
	string newTiles[ROOM_HEIGHT] = {
		"....#",
		"....#",
		".....",
		"....#",
		"#####"
	};
	copyRoom(newTiles);
}

void Room::initRoom32()
{
	northID = 3;
	eastID = 4;
	southID = 1;
	westID = 0;
	string newTiles[ROOM_HEIGHT] = {
		"#....",
		"#....",
		"#....",
		"#....",
		"##.##"
	};
	copyRoom(newTiles);
}

void Room::initRoom33()
{
	northID = 0;
	eastID = 3;
	southID = 3;
	westID = 1;
	string newTiles[ROOM_HEIGHT] = {
		"#####",
		"#....",
		".....",
		"#....",
		"#...."
	};
	copyRoom(newTiles);
}

void Room::initRoom34()
{
	northID = 0;
	eastID = 1;
	southID = 4;
	westID = 3;
	string newTiles[ROOM_HEIGHT] = {
		"#####",
		"....#",
		".....",
		"....#",
		"....#"
	};
	copyRoom(newTiles);
}

void Room::initRoom35()
{
	northID = 4;
	eastID = 0;
	southID = 1;
	westID = 4;
	string newTiles[ROOM_HEIGHT] = {
		"....#",
		"....#",
		"....#",
		"....#",
		"##.##"
	};
	copyRoom(newTiles);
}

void Room::initRoom36()
{
	northID = 3;
	eastID = 4;
	southID = 0;
	westID = 1;
	string newTiles[ROOM_HEIGHT] = {
		"#....",
		"#....",
		".....",
		"#....",
		"#####"
	};
	copyRoom(newTiles);
}

void Room::initRoom37()
{
	northID = 1;
	eastID = 3;
	southID = 3;
	westID = 0;
	string newTiles[ROOM_HEIGHT] = {
		"##.##",
		"#....",
		"#....",
		"#....",
		"#...."
	};
	copyRoom(newTiles);
}

void Room::initRoom38()
{
	northID = 1;
	eastID = 1;
	southID = 4;
	westID = 3;
	string newTiles[ROOM_HEIGHT] = {
		"##.##",
		"....#",
		".....",
		"....#",
		"....#"
	};
	copyRoom(newTiles);
}

void Room::initRoom39()
{
	northID = 4;
	eastID = 1;
	southID = 1;
	westID = 4;
	string newTiles[ROOM_HEIGHT] = {
		"....#",
		"....#",
		".....",
		"....#",
		"##.##"
	};
	copyRoom(newTiles);
}

void Room::initRoom40()
{
	northID = 3;
	eastID = 4;
	southID = 1;
	westID = 1;
	string newTiles[ROOM_HEIGHT] = {
		"#....",
		"#....",
		".....",
		"#....",
		"##.##"
	};
	copyRoom(newTiles);
}

void Room::initRoom41()
{
	northID = 1;
	eastID = 3;
	southID = 3;
	westID = 1;
	string newTiles[ROOM_HEIGHT] = {
		"##.##",
		"#....",
		".....",
		"#....",
		"#...."
	};
	copyRoom(newTiles);
}

void Room::initRoom42()
{
	northID = 3;
	eastID = 4;
	southID = 4;
	westID = 3;
	string newTiles[ROOM_HEIGHT] = {
		"#....",
		".....",
		".....",
		".....",
		"....#"
	};
	copyRoom(newTiles);
}

void Room::initRoom43()
{
	northID = 4;
	eastID = 3;
	southID = 3;
	westID = 4;
	string newTiles[ROOM_HEIGHT] = {
		"....#",
		".....",
		".....",
		".....",
		"#...."
	};
	copyRoom(newTiles);
}

void Room::initRoom44()
{
	northID = 0;
	eastID = 0;
	southID = 4;
	westID = 2;
	string newTiles[ROOM_HEIGHT] = {
		"#####",
		"....#",
		"....#",
		"....#",
		"....#"
	};
	copyRoom(newTiles);
}

void Room::initRoom45()
{
	northID = 2;
	eastID = 0;
	southID = 0;
	westID = 4;
	string newTiles[ROOM_HEIGHT] = {
		"....#",
		"....#",
		"....#",
		"....#",
		"#####"
	};
	copyRoom(newTiles);
}

void Room::initRoom46()
{
	northID = 3;
	eastID = 2;
	southID = 0;
	westID = 0;
	string newTiles[ROOM_HEIGHT] = {
		"#....",
		"#....",
		"#....",
		"#....",
		"#####"
	};
	copyRoom(newTiles);
}

void Room::initRoom47()
{
	northID = 0;
	eastID = 3;
	southID = 2;
	westID = 0;
	string newTiles[ROOM_HEIGHT] = {
		"#####",
		"#....",
		"#....",
		"#....",
		"#...."
	};
	copyRoom(newTiles);
}

void Room::initRoom48()
{
	northID = 0;
	eastID = 0;
	southID = 2;
	westID = 3;
	string newTiles[ROOM_HEIGHT] = {
		"#####",
		"....#",
		"....#",
		"....#",
		"....#"
	};
	copyRoom(newTiles);
}

void Room::initRoom49()
{
	northID = 4;
	eastID = 0;
	southID = 0;
	westID = 2;
	string newTiles[ROOM_HEIGHT] = {
		"....#",
		"....#",
		"....#",
		"....#",
		"#####"
	};
	copyRoom(newTiles);
}

void Room::initRoom50()
{
	northID = 2;
	eastID = 4;
	southID = 0;
	westID = 0;
	string newTiles[ROOM_HEIGHT] = {
		"#....",
		"#....",
		"#....",
		"#....",
		"#####"
	};
	copyRoom(newTiles);
}

void Room::initRoom51()
{
	northID = 0;
	eastID = 2;
	southID = 3;
	westID = 0;
	string newTiles[ROOM_HEIGHT] = {
		"#####",
		"#....",
		"#....",
		"#....",
		"#...."
	};
	copyRoom(newTiles);
}