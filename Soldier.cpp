#include "Soldier.h"
#include "Rad.h"
#include "Actor.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"

// Constructors:

Soldier::Soldier(Rad *t, Actor* a)
	:Character(t, a)
{
}

Soldier::~Soldier()
{
}

// Getters:

string Soldier::getRole() {
	return "Soldier";
}

int Soldier::getBAB() {
	return calculateLevel();
}

int Soldier::getHitDie() {
	return 10;
}

int Soldier::getFortitude() {
	return 2 + (int)floor((2 / (float)3) * (float)calculateLevel()) + rad->calculateModifier(getConstitution());
}

int Soldier::getReflex() {
	return 0 + (int)floor((1 / (float)3) * (float)calculateLevel()) + rad->calculateModifier(getDexterity());
}

int Soldier::getWill() {
	return 0 + (int)floor((1 / (float)3) * (float)calculateLevel()) + rad->calculateModifier(getWisdom());
}

string Soldier::getMainAbility1() {
	return "str";
}

string Soldier::getMainAbility2() {
	return "dex";
}

string Soldier::getMainAbility3() {
	return "con";
}

void Soldier::initializeItems()
{
	items.push_back(new Armor(rad, ITEM_ARMOR, 1, "Ballistic Vest", 0, true, true, 3, 8, -1, 5));
	items.push_back(new Weapon(rad, ITEM_WEAPON, 1, "Rifle", 0, true, true, true, 80, 2, 8, DAMAGE_PHYSICAL, AMMO_BULLET));
	items.push_back(new Item(rad, ITEM_AMMO, 1, "Bullets", 40, true, false));	
}
