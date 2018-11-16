#include "Weapon.h"
#include "Rad.h"
#include "Character.h"
#include "Spell.h"

// Constructors and Destructors //

Weapon::Weapon(Rad* t, int i, int l, string n, int v, bool d, bool e, bool r, int ri, int nd, int dd, int dt, int at)
	:Item(t, i, l, n, v, d, e)
{
	ranged = r;
	range = ri;
	numDice = nd;
	damage = dd;
	damageType = dt;
	ammoType = at;
}

// Functions //

// Getters:

bool Weapon::getRanged()
{
	return ranged;
}

int Weapon::getRange()
{
	return range;
}

int Weapon::getNumDice()
{
	return numDice;
}

int Weapon::getDamage()
{
	return damage;
}

int Weapon::getDamageType()
{
	return damageType;
}

int Weapon::getAmmoType()
{
	return ammoType;
}

// Misc:

int Weapon::rollDamage() {
	return numDice * rad->d(damage);
}
