#include "Psychic.h"
#include "Rad.h"
#include "Actor.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"

// Constructors:

Psychic::Psychic(Rad *t, Actor* a)
	:Character(t, a)
{
}

Psychic::~Psychic()
{
}

// Getters:

string Psychic::getRole() {
	return "Psychic";
}

int Psychic::getBAB() {
	return (int)floor((1 / (float)2) * (float)calculateLevel());
}

int Psychic::getHitDie() {
	return 6;
}

int Psychic::getFortitude() {
	return 0 + (int)floor((1 / (float)3) * (float)calculateLevel()) + rad->calculateModifier(getConstitution());
}

int Psychic::getReflex() {
	return 0 + (int)floor((1 / (float)3) * (float)calculateLevel()) + rad->calculateModifier(getDexterity());
}

int Psychic::getWill() {
	return 2 + (int)floor((2 / (float)3) * (float)calculateLevel()) + rad->calculateModifier(getWisdom());
}

string Psychic::getMainAbility1() {
	return "cha";
}

string Psychic::getMainAbility2() {
	return "wis";
}

string Psychic::getMainAbility3() {
	return "con";
}

void Psychic::initializeItems()
{
	items.push_back(new Armor(rad, ITEM_ARMOR, 1, "Coveralls", 0, true, true, 1, 10, -0, 0));
	items.push_back(new Weapon(rad, ITEM_WEAPON, 1, "Worn Pistol", 0, true, true, true, 20, 1, 4, DAMAGE_PHYSICAL, AMMO_BULLET));
	items.push_back(new Item(rad, ITEM_AMMO, 1, "Bullets", 20, true, false));	
}
