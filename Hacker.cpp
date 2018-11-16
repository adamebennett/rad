#include "Hacker.h"
#include "Rad.h"
#include "Actor.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"


// Constructors:

Hacker::Hacker(Rad *t, Actor* a)
	:Character(t, a)
{
}

Hacker::~Hacker()
{
}

// Getters:

string Hacker::getRole() {
	return "Hacker";
}

int Hacker::getBAB() {
	return (int)floor((3 / (float)4) * (float)calculateLevel());
}

int Hacker::getHitDie() {
	return 8;
}

int Hacker::getFortitude() {
	return 0 + (int)floor((1 / (float)3) * (float)calculateLevel()) + rad->calculateModifier(getConstitution());
}

int Hacker::getReflex() {
	return 2 + (int)floor((2 / (float)3) * (float)calculateLevel()) + rad->calculateModifier(getDexterity());
}

int Hacker::getWill() {
	return 0 + (int)floor((1 / (float)3) * (float)calculateLevel()) + rad->calculateModifier(getWisdom());
}

string Hacker::getMainAbility1() {
	return "int";
}

string Hacker::getMainAbility2() {
	return "dex";
}

string Hacker::getMainAbility3() {
	return "con";
}

void Hacker::initializeItems()
{
	items.push_back(new Armor(rad, ITEM_ARMOR, 1, "Coveralls", 0, true, true, 1, 10, -0, 0));
	items.push_back(new Weapon(rad, ITEM_WEAPON, 1, "Plasma Torch", 0, true, true, false, 0, 2, 4, DAMAGE_FIRE, AMMO_BATTERY));
	items.push_back(new Item(rad, ITEM_AMMO, 1, "Batteries", 20, true, false));
}
