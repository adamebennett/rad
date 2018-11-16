#include "Armor.h"
#include "Rad.h"
#include "Character.h"
#include "Spell.h"

// Constructors and Destructors //

Armor::Armor(Rad* t, int i, int l, string n, int v, bool d, bool e, int a, int md, int check, int fail)
	:Item(t, i, l, n, v, d, e)
{
	armorValue = a;
	maxDex = md;
	armorCheck = check;
	failureChance = fail;
}

// Functions //

// Getters:

int Armor::getArmorValue()
{
	return armorValue;
}

int Armor::getMaxDex()
{
	return maxDex;
}

int Armor::getArmorCheck()
{
	return armorCheck;
}

int Armor::getFailureChance()
{
	return failureChance;
}
