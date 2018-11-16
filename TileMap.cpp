#include "TileMap.h"
#include "Rad.h"
#include "Room.h"

// Constructors and Destructors //

TileMap::TileMap(Graphics* g, Rad* t, int i)
{
	graphics = g;
	rad = t;
	level = i;
	rooms.push_back(new Room(0));
	rooms.push_back(new Room(1));
	rooms.push_back(new Room(2));
	rooms.push_back(new Room(3));
	rooms.push_back(new Room(4));
	rooms.push_back(new Room(5));
	rooms.push_back(new Room(6));
	rooms.push_back(new Room(7));
	rooms.push_back(new Room(8));
	rooms.push_back(new Room(9));
	rooms.push_back(new Room(10));
	rooms.push_back(new Room(11));
	rooms.push_back(new Room(12));
	rooms.push_back(new Room(13));
	rooms.push_back(new Room(14));
	rooms.push_back(new Room(15));
	rooms.push_back(new Room(16));
	rooms.push_back(new Room(17));
	rooms.push_back(new Room(18));
	rooms.push_back(new Room(19));
	rooms.push_back(new Room(20));
	rooms.push_back(new Room(21));
	rooms.push_back(new Room(22));
	rooms.push_back(new Room(23));
	rooms.push_back(new Room(24));
	rooms.push_back(new Room(25));
	rooms.push_back(new Room(26));
	rooms.push_back(new Room(27));
	rooms.push_back(new Room(28));
	rooms.push_back(new Room(29));
	rooms.push_back(new Room(30));
	rooms.push_back(new Room(31));
	rooms.push_back(new Room(32));
	rooms.push_back(new Room(33));
	rooms.push_back(new Room(34));
	rooms.push_back(new Room(35));
	rooms.push_back(new Room(36));
	rooms.push_back(new Room(37));
	rooms.push_back(new Room(38));
	rooms.push_back(new Room(39));
	rooms.push_back(new Room(40));
	rooms.push_back(new Room(41));
	rooms.push_back(new Room(42));
	rooms.push_back(new Room(43));
	/*rooms.push_back(new Room(44));
	rooms.push_back(new Room(45));
	rooms.push_back(new Room(46));
	rooms.push_back(new Room(47));
	rooms.push_back(new Room(48));
	rooms.push_back(new Room(49));
	rooms.push_back(new Room(50));*/
	for (int i = 0; i < MAP_WIDTH; ++i)
	{
		for (int j = 0; j < MAP_HEIGHT; ++j)
		{
			map[i][j] = new SolidTile();
		}
	}
	initializeMap(round(NUM_ROOMS_X / 2),round(NUM_ROOMS_Y / 2));
}

TileMap::~TileMap()
{	
	for (int i = 0; i < rooms.size(); i++)
	{
		if (rooms[i] != NULL)
		{
			delete(rooms[i]);
		}
	}
}

// Functions //

// Misc:

void TileMap::draw(int offsetX, int offsetY) const
{
	for (int i = 0; i < MAP_WIDTH; ++i)
	{
		for (int j = 0; j < MAP_HEIGHT; ++j)
		{
			if (map[i][j]->getVisible() || map[i][j]->getRevealed())
			{
				Graphic graphic = map[i][j]->getGraphic();
				graphic.moveTo(i, j);
				graphics->drawGraphicInvertedCentred(graphic, offsetX, offsetY);
			}
		}
	}
}

void TileMap::hide()
{
	for (int i = 0; i < MAP_WIDTH; ++i)
	{
		for (int j = 0; j < MAP_HEIGHT; ++j)
		{
			map[i][j]->setVisible(false);
		}
	}
}

Tile* TileMap::getTile(int x, int y)
{
	if (map[x][y] != 0)
	{
		return map[x][y];
	}
}

bool TileMap::isSolid(int x, int y)
{
	if (map[x][y] != 0)
	{
		return map[x][y]->isSolid();
	}
}

void TileMap::replaceTile(int x, int y, Tile* newTile)
{
	if (map[x][y] != 0)
	{
		delete(map[x][y]);
		map[x][y] = newTile;
	}
}

bool TileMap::getVisible(int x, int y)
{
	if (map[x][y] != 0)
	{
		return map[x][y]->getVisible();
	}
	return false;
}

void TileMap::setVisible(int x, int y, bool b)
{
	if (map[x][y] != 0)
	{
		map[x][y]->setVisible(b);
	}
}

bool TileMap::getRevealed(int x, int y)
{
	if (map[x][y] != 0)
	{
		return map[x][y]->getRevealed();
	}
	return false;
}

void TileMap::setRevealed(int x, int y, bool b)
{
	if (map[x][y] != 0)
	{
		map[x][y]->setRevealed(b);
	}
}

NPC* TileMap::placeNPC(Character* c)
{
	for (int i = 1; i < MAP_WIDTH - 1; ++i)
	{
		for (int j = 1; j < MAP_HEIGHT - 1; ++j)
		{
			int totalTiles = MAP_WIDTH * MAP_HEIGHT;
			if (rad->d(totalTiles) == 1)
			{
				if (!rad->isSolid(i,j))
				{
					return new NPC(rad, c, i, j, level);
				}
			}
		}
	}
	return NULL;
}

void TileMap::positionPlayer(Player* player)
{
	int numSpots = 0;
	int spotsX[MAP_WIDTH*MAP_HEIGHT];
	int spotsY[MAP_WIDTH*MAP_HEIGHT];
	for (int i = 1; i < MAP_WIDTH - 1; ++i)
	{
		for (int j = 1; j < MAP_HEIGHT - 1; ++j)
		{
			if (!isSolid(i,j))
			{
				spotsX[numSpots] = i;
				spotsY[numSpots] = j;
				numSpots++;
			}
		}
	}
	int chosenSpot = rad->d(numSpots + 1) - 1;
	player->getCharacter()->moveTo(spotsX[chosenSpot], spotsY[chosenSpot]);
}

void TileMap::initializeMap(int x, int y)
{
	for (int i = 0; i < NUM_ROOMS_X; ++i)
	{
		for (int j = 0; j < NUM_ROOMS_Y; ++j)
		{
			roomsToLoad[i][j] = rooms[0];
		}
	}
	generateRooms(x, y, -1, -1, -1, -1, rooms[2]);
	loadRooms();
	addStairs();
	fillBorder();
}

void TileMap::generateRooms(int x, int y, int n, int e, int s, int w, Room* startingRoom)
{	
	if (x < 0 || x >= NUM_ROOMS_X || y < 0 || y >= NUM_ROOMS_Y)
	{
		return;
	}
	if (roomsToLoad[x][y]->getID() != 0)
	{
		return;
	}
	
	if (n == -1 && y + 1 < NUM_ROOMS_Y)
	{
		if (roomsToLoad[x][y+1]->getID() != 0)
		{
			n = roomsToLoad[x][y+1]->getSouthID();
		}
	}
	if (s == -1 && y - 1 >= 0)
	{
		if (roomsToLoad[x][y-1]->getID() != 0)
		{
			s = roomsToLoad[x][y-1]->getNorthID();
		}
	}
	if (e == -1 && x + 1 < NUM_ROOMS_X)
	{
		if (roomsToLoad[x + 1][y]->getID() != 0)
		{
			e = roomsToLoad[x + 1][y]->getWestID();
		}
	}
	if (w == -1 && x - 1 >= 0)
	{
		if (roomsToLoad[x - 1][y]->getID() != 0)
		{
			w = roomsToLoad[x - 1][y]->getEastID();
		}
	}
	if (x - 1 < 0)
		w = 0;
	if (x + 1 >= NUM_ROOMS_X)
		e = 0;
	if (y - 1 < 0)
		s = 0;
	if (y + 1 >= NUM_ROOMS_Y)
		n = 0;
	
	Room* room;
	if (startingRoom != NULL)
	{
		room = startingRoom;
	}
	else
	{
		room = getRoom(n, e, s, w);
	}
	roomsToLoad[x][y] = room;
	if (room->getWestID() != 0)
		generateRooms(x - 1, y, -1, room->getWestID(), -1, -1, NULL);
	if (room->getEastID() != 0)
		generateRooms(x + 1, y, -1, -1, -1, room->getEastID(), NULL);
	if (room->getNorthID() != 0)
		generateRooms(x, y + 1, -1, -1, room->getNorthID(), -1, NULL);
	if (room->getSouthID() != 0)
		generateRooms(x, y - 1, room->getSouthID(), -1, -1, -1, NULL);
	
	return;
}

Room* TileMap::getRoom(int n, int e, int s, int w)
{
	vector<Room*> correctRooms;
	for (int i = 0; i < rooms.size(); ++i)
	{
		if (n == -1 || rooms[i]->getNorthID() == n)
		{			
			if (e == -1 || rooms[i]->getEastID() == e)
			{
				if (s == -1 || rooms[i]->getSouthID() == s)
				{
					if (w == -1 || rooms[i]->getWestID() == w)
					{
						correctRooms.push_back(rooms[i]);
					}
				}
			}
		}
	}	
	if (correctRooms.size() > 0)
	{
		int pickedTile = rad->d(correctRooms.size()) - 1;
		if (pickedTile < 0 || pickedTile >= correctRooms.size())
			pickedTile = 0;
		return correctRooms[pickedTile];
	}
	else
		return rooms[1];
}

void TileMap::loadRooms()
{
	for (int i = 0; i < NUM_ROOMS_X; ++i)
	{
		for (int j = 0; j < NUM_ROOMS_Y; ++j)
		{
			for (int y = 0; y < ROOM_HEIGHT; ++y)
			{
				for (int x = 0; x < ROOM_WIDTH; ++x)
				{
					Tile* tile;
					if (roomsToLoad[i][j]->getTile(x, y) == ' ')
					{
						tile = new StoneTile();
					}
					else if (roomsToLoad[i][j]->getTile(x, y) == '.')
					{
						tile = new Tile();
					}
					else if (roomsToLoad[i][j]->getTile(x, y) == '#')
					{
						tile = new WallTile();
					}
					if (tile != NULL)
					{
						replaceTile(i * ROOM_WIDTH + x + 1, j * ROOM_HEIGHT + y + 1, tile);
					}
				}
			}
		}
	}
}

void TileMap::fillBorder()
{
	for (int i = 0; i < MAP_WIDTH; ++i)
	{
		for (int j = 0; j < MAP_HEIGHT; ++j)
		{
			if (i== 0 || i == MAP_WIDTH - 1 || j == 0 || j == MAP_HEIGHT - 1)
			{
				replaceTile(i, j, new SolidTile());
			}
		}
	}
}

void TileMap::addStairs()
{
	int numSpots = 0;
	int spotsX[MAP_WIDTH*MAP_HEIGHT];
	int spotsY[MAP_WIDTH*MAP_HEIGHT];
	for (int i = 1; i < MAP_WIDTH - 1; ++i)
	{
		for (int j = 1; j < MAP_HEIGHT - 1; ++j)
		{
			if (!isSolid(i,j))
			{
				spotsX[numSpots] = i;
				spotsY[numSpots] = j;
				numSpots++;
			}
		}
	}
	int chosenSpot = rad->d(numSpots + 1) - 1;
	replaceTile(spotsX[chosenSpot], spotsY[chosenSpot], new StairTile());
}