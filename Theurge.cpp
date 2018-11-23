#include "Theurge.h"
#include "Rad.h"
#include "Actor.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"

// Constructors:

Theurge::Theurge(Rad *t, Actor* a)
	:Character(t, a)
{
}

Theurge::~Theurge()
{
}

// Getters:

string Theurge::getRole() {
	return "Theurge";
}

int Theurge::getBAB() {
	return (int)floor((1 / (float)2) * (float)calculateLevel());
}

int Theurge::getHitDie() {
	return 6;
}

int Theurge::getFortitude() {
	return 0 + (int)floor((1 / (float)3) * (float)calculateLevel()) + rad->calculateModifier(getConstitution());
}

int Theurge::getReflex() {
	return 0 + (int)floor((1 / (float)3) * (float)calculateLevel()) + rad->calculateModifier(getDexterity());
}

int Theurge::getWill() {
	return 2 + (int)floor((2 / (float)3) * (float)calculateLevel()) + rad->calculateModifier(getWisdom());
}

string Theurge::getMainAbility1() {
	return "cha";
}

string Theurge::getMainAbility2() {
	return "wis";
}

string Theurge::getMainAbility3() {
	return "con";
}

void Theurge::initializeItems()
{
	items.push_back(new Armor(rad, ITEM_ARMOR, 1, "Coveralls", 0, true, true, 1, 10, -0, 0));
	items.push_back(new Weapon(rad, ITEM_WEAPON, 1, "Worn Pistol", 0, true, true, true, 20, 1, 4, DAMAGE_PHYSICAL, AMMO_BULLET));
	items.push_back(new Item(rad, ITEM_AMMO, 1, "Bullets", 20, true, false));	
}
