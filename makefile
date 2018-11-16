TILE_FILES = Tile.o SolidTile.o StoneTile.o WallTile.o StairTile.o
ITEM_FILES = Item.o Armor.o Weapon.o
ROLE_FILES = Soldier.o Hacker.o Psychic.o
OBJ_FILES = main.o Rad.o MainMenu.o Graphics.o Player.o NPC.o Hud.o Character.o Entity.o $(ITEM_FILES) ${ROLE_FILES} Spell.o Projectile.o Graphic.o miscFunctions.o $(TILE_FILES) TileMap.o Room.o
LINK_OPTIONS = -lncurses

rad: $(OBJ_FILES)
	g++ -o rad $(OBJ_FILES) $(LINK_OPTIONS)
	
main.o: main.cpp Rad.o
	g++ -c -g main.cpp
	
Rad.o: Rad.h Rad.cpp
	g++ -c -g Rad.cpp	
	
MainMenu.o: MainMenu.h MainMenu.cpp
	g++ -c -g MainMenu.cpp	
	
Graphic.o: Graphic.h Graphic.cpp
	g++ -c -g Graphic.cpp
	
Graphics.o: Graphics.h Graphics.cpp
	g++ -c -g Graphics.cpp

Player.o: Player.h Player.cpp
	g++ -c -g Player.cpp

NPC.o: NPC.h NPC.cpp
	g++ -c -g NPC.cpp
	
Hud.o: Hud.h Hud.cpp
	g++ -c -g Hud.cpp
	
Character.o: Character.h Character.cpp
	g++ -c -g Character.cpp
	
Role.o: Role.h Role.cpp
	g++ -c -g Role.cpp
	
Soldier.o: Soldier.h Soldier.cpp
	g++ -c -g Soldier.cpp
	
Hacker.o: Hacker.h Hacker.cpp
	g++ -c -g Hacker.cpp
	
Psychic.o: Psychic.h Psychic.cpp
	g++ -c -g Psychic.cpp
	
Entity.o: Entity.h Entity.cpp
	g++ -c -g Entity.cpp
	
Item.o: Item.h Item.cpp
	g++ -c -g Item.cpp
	
Armor.o: Armor.h Armor.cpp
	g++ -c -g Armor.cpp
	
Weapon.o: Weapon.h Weapon.cpp
	g++ -c -g Weapon.cpp
	
Spell.o: Spell.h Spell.cpp
	g++ -c -g Spell.cpp
	
Projectile.o: Projectile.h Projectile.cpp
	g++ -c -g Projectile.cpp
	
Tile.o: Tile.h Tile.cpp
	g++ -c -g Tile.cpp
	
SolidTile.o: SolidTile.h SolidTile.cpp
	g++ -c -g SolidTile.cpp
	
StoneTile.o: StoneTile.h StoneTile.cpp
	g++ -c -g StoneTile.cpp
	
WallTile.o: WallTile.h WallTile.cpp
	g++ -c -g WallTile.cpp
	
StairTile.o: StairTile.h StairTile.cpp
	g++ -c -g StairTile.cpp
	
TileMap.o: TileMap.h TileMap.cpp
	g++ -c -g TileMap.cpp
	
Room.o: Room.h Room.cpp
	g++ -c -g Room.cpp
	
miscFunctions.o: miscFunctions.h miscFunctions.cpp
	g++ -c -g miscFunctions.cpp
	
clean:
	rm *.o rad