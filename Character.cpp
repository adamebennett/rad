#include "Character.h"
#include "Rad.h"
#include "Actor.h"
#include "Item.h"
#include "Armor.h"
#include "Weapon.h"
#include "Spell.h"

// Constructors and Destructors //

Character::Character(Rad *t, Actor* a)
	:Entity(t)
{
	name = "Unknown";
	actor = a;
	faction = 0;
	xp = 0;
	strength = 10;
	constitution = 10;
	dexterity = 10;
	intelligence = 10;
	wisdom = 10;
	charisma = 10;
	size = SIZE_MEDIUM;
	health = 1;
	maxHealth = 1;
	energy = 0;
	items = vector<Item*>();
	message = "";
}

Character::~Character()
{
}
		
// Functions //
		
// Getters

string Character::getName()
{
	return name;
}

Actor* Character::getActor()
{
	return actor;
}

int Character::getFaction()
{
	return faction;
}

int Character::getXP() {
	return xp;
}

int Character::getStrength()
{
	return strength;
}

int Character::getDexterity()
{
	return dexterity;
}

int Character::getConstitution()
{
	return constitution;
}

int Character::getIntelligence()
{
	return intelligence;
}

int Character::getWisdom()
{
	return wisdom;
}

int Character::getCharisma()
{
	return charisma;
}

int Character::getSize()
{
	return size;
}

int Character::getHealth()
{
	return health;
}

int Character::getMaxHealth()
{
	return maxHealth;
}

int Character::getEnergy()
{
	return energy;
}

int Character::getMaxEnergy()
{
	/*if (role == NULL)
	{
		return 0;
	}
	if (role->getMaxSpellLevel() > 0)
	{
		int points = 0;
		for (int i = 1; i <= role->getMaxSpellLevel(); ++i)
		{
			int minLevel = (i * 2) - 1;
			int diff = role->getLevel() - minLevel;
			if (diff == 0)
				points += 1;
			else if (diff >= 1 && diff <= 2)
				points += 2;
			else if (diff >= 3 && diff <= 5)
				points += 3;
			else
				points += 4;
		}
		// bonus magic points		
		for (int i = 1; i <= role->getMaxSpellLevel(); ++i)
		{
			points += ceil((rad->calculateModifier(intelligence) - (i - 1)) / 4.0) * i;
		}
		return points;
	}*/
	return 0;
}

int Character::getCMB()
{
	return getBAB() + rad->calculateModifier(strength) - size;
}

int Character::getCMD()
{
	return 10 + getBAB() + rad->calculateModifier(strength) + rad->calculateModifier(dexterity) - size;
}

int Character::getArmorClass()
{
	int armorClass = 10;
	int maxDexBonus = 500;
	for (int i = 0; i < items.size(); ++i)
	{
		if (items[i]->getEquipped() && (items[i]->getItemType() == ITEM_ARMOR))
		{
			Armor* armor = (Armor*)items[i];
			armorClass = armorClass + armor->getArmorValue();
			maxDexBonus = min(maxDexBonus, armor->getMaxDex());
		}
		else if (items[i]->getEquipped() && items[i]->getItemType() == ITEM_AMULET)
		{
			if (items[i]->getName() == "Amulet of Protection")
			{
				armorClass += items[i]->getValue();
			}
		}
	}
	if (maxDexBonus > rad->calculateModifier(dexterity))
	{
		armorClass += rad->calculateModifier(dexterity);
	}
	else
	{
		armorClass += maxDexBonus;
	}
	armorClass += size;	
	return armorClass;
}

int Character::getArmorCheck()
{
	int armorCheck = 0;
	for (int i = 0; i < items.size(); ++i)
	{
		if (items[i]->getEquipped() && (items[i]->getItemType() == ITEM_ARMOR))
		{
			Armor* armor = (Armor*)items[i];
			armorCheck += armor->getArmorCheck();
		}
	}
	return armorCheck;
}

int Character::getSpellFailure()
{
	int failure = 0;
	for (int i = 0; i < items.size(); ++i)
	{
		if (items[i]->getEquipped() && (items[i]->getItemType() == ITEM_ARMOR))
		{
			Armor* armor = (Armor*)items[i];
			failure += armor->getFailureChance();
		}
	}
	return failure;
}

int Character::getAttackBonus()
{
	int bonus = 0;
	bonus += getBAB();
	bonus += size;
	if (!ranged())
		bonus += rad->calculateModifier(strength);
	else
		bonus += rad->calculateModifier(dexterity);
	return bonus;
}

int Character::getAttackRoll()
{
	return rad->d(20) + getAttackBonus();
}

int Character::getDamageRoll(Character* c)
{	
	int damage = 0;
	bool unarmed = true;
	for (int i = 0; i < items.size(); ++i)
	{
		if (items[i]->getEquipped() && items[i]->getItemType() == ITEM_WEAPON)
		{
			unarmed = false;
			Weapon* weapon = (Weapon*)items[i];
			if (ranged())
			{
				damage = rad->d(weapon->rollDamage());
			}
			else
			{
				damage = rad->d(weapon->rollDamage() + rad->calculateModifier(strength));
			}
		}
	}
	// Unarmed:
	if (unarmed)
	{
		if (getSize() == SIZE_TINY) {
			damage = rad->d(2) + rad->calculateModifier(strength);
		}
		else if (getSize() == SIZE_SMALL) {
			damage = rad->d(3) + rad->calculateModifier(strength);
		}
		else if (getSize() == SIZE_MEDIUM) {
			damage = rad->d(4) + rad->calculateModifier(strength);
		}
		else if (getSize() == SIZE_LARGE) {
			damage = rad->d(6) + rad->calculateModifier(strength);
		}
		else if (getSize() == SIZE_HUGE) {
			damage = rad->d(8) + rad->calculateModifier(strength);
		}
	}
	
	return max(1, damage);
}

Weapon* Character::getWeapon()
{
	for (int i = 0; i < items.size(); ++i)
	{
		if (items[i]->getEquipped() && items[i]->getItemType() == ITEM_WEAPON)
		{
			return (Weapon*)items[i];
		}
	}
	return NULL;
}

vector<Item*> Character::getItems() {
	return items;
}

string Character::getMessage()
{
	return message;
}

// Setters

void Character::setName(string s)
{
	name = s;
}

void Character::setFaction(int i)
{
	faction = i;
}

void Character::setActor(Actor* a)
{
	actor = a;
}

void Character::setXP(int x) {
	xp = x;
}

void Character::setHealth(int h)
{
	health = h;
}

void Character::setEnergy(int e)
{
	energy = e;
}

void Character::setMessage(string m)
{
	message = m;
}
	
// Misc

void Character::update()
{
	restore();
}

int Character::calculateLevel() {
	return (int)floor(1 + sqrt(xp / 10));
}

void Character::restore()
{
	// Restore hit points
	float conMod = rad->calculateModifier(constitution);
	int turnsPerPoint = 10;
	if (conMod > -1)
	{
		turnsPerPoint = (int)(floor(600 / (1 + conMod)));
	}
	else if (conMod < -1)
	{
		turnsPerPoint = (int)(floor(600 * (1 - conMod)));
	}
	if (((int)(rad->getTurns() % turnsPerPoint) == 0))
	{
		health++;
		if (health > maxHealth)
		{
			health = maxHealth;
		}
	}
	
	// Restore energy
	float intMod = rad->calculateModifier(intelligence);
	turnsPerPoint = 10;
	if (intMod > -1)
	{
		turnsPerPoint = (int)(floor(600 / (1 + intMod)));
	}
	else if (intMod < -1)
	{
		turnsPerPoint = (int)(floor(600 * (1 - intMod)));
	}
	if (((int)(rad->getTurns() % turnsPerPoint) == 0))
	{
		energy++;
		if (energy > getMaxEnergy())
		{
			energy = getMaxEnergy();
		}
	}
}

bool Character::ranged()
{	
	Weapon* weapon = getWeapon();
	if (weapon == NULL)
	{
		return false;
	}
	else
	{
		return weapon->getRanged();
	}
}

bool Character::useWeapon()
{
	Weapon* w = getWeapon();
	if (w == NULL) {
		return true; // unarmed
	}
	if (w->getAmmoType() == AMMO_NONE) {
		return true;
	}
	string requiredAmmo = string("");
	if (w->getAmmoType() == AMMO_BULLET) {
		requiredAmmo = string("Bullets");
	}
	else if (w->getAmmoType() == AMMO_BATTERY) {
		requiredAmmo = string("Batteries");
	}
	int index = -1;
	for (int i = 0; i < items.size(); ++i) {
		if (items[i]->getItemType() == ITEM_AMMO && items[i]->getName().compare(requiredAmmo) == 0) {
			if (items[i]->getValue() > 0) {
				index = i;
				break;
			}
		}
	}
	if (index != -1) {
		items[index]->setValue(items[index]->getValue() - 1);
		if (items[index]->getValue() == 0) {
			items.erase(items.begin() + index);
		}
		return true;
	}
	return false;
}

void Character::initializeAbilityScores()
{
	vector<int> scores;
	for (int i = 0; i < 6; ++i)
	{
		vector<int> rolls;
		for (int j = 0; j < 4; ++j)
		{
			rolls.push_back(rad->d(6));
		}
		sort(rolls.begin(), rolls.end());
		int score = 0;
		for (int j = 1; j < rolls.size(); ++j)
		{
			score = score + rolls[j];
		}
		scores.push_back(score);
	}
	sort(scores.begin(), scores.end());
	
	vector<int> lowScores;
	for (int i = 0; i < 3; i++)
	{
		lowScores.push_back(scores[i]);
	}
	random_shuffle(lowScores.begin(), lowScores.end());
	
	if (getMainAbility1() == "str")
	{
		strength = scores[5];
	}
	else if (getMainAbility1() == "dex")
	{
		dexterity = scores[5];
	}
	else if (getMainAbility1() == "con")
	{
		constitution = scores[5];
	}
	else if (getMainAbility1() == "int")
	{
		intelligence = scores[5];
	}
	else if (getMainAbility1() == "wis")
	{
		wisdom = scores[5];
	}
	else if (getMainAbility1() == "cha")
	{
		charisma = scores[5];
	}
	
	if (getMainAbility2() == "str")
	{
		strength = scores[4];
	}
	else if (getMainAbility2() == "dex")
	{
		dexterity = scores[4];
	}
	else if (getMainAbility2() == "con")
	{
		constitution = scores[4];
	}
	else if (getMainAbility2() == "int")
	{
		intelligence = scores[4];
	}
	else if (getMainAbility2() == "wis")
	{
		wisdom = scores[4];
	}
	else if (getMainAbility2() == "cha")
	{
		charisma = scores[4];
	}
	
	if (getMainAbility3() == "str")
	{
		strength = scores[3];
	}
	else if (getMainAbility3() == "dex")
	{
		dexterity = scores[3];
	}
	else if (getMainAbility3() == "con")
	{
		constitution = scores[3];
	}
	else if (getMainAbility3() == "int")
	{
		intelligence = scores[3];
	}
	else if (getMainAbility3() == "wis")
	{
		wisdom = scores[3];
	}
	else if (getMainAbility3() == "cha")
	{
		charisma = scores[3];
	}
	
	int lowIndex = 2;
	if (getMainAbility1() != "str" && getMainAbility2() != "str" && getMainAbility3() != "str")
	{
		strength = lowScores[lowIndex];
		lowIndex--;
	}
	if (getMainAbility1() != "dex" && getMainAbility2() != "dex" && getMainAbility3() != "dex")
	{
		dexterity = lowScores[lowIndex];
		lowIndex--;
	}
	if (getMainAbility1() != "con" && getMainAbility2() != "con" && getMainAbility3() != "con")
	{
		constitution = lowScores[lowIndex];
		lowIndex--;
	}
	if (getMainAbility1() != "int" && getMainAbility2() != "int" && getMainAbility3() != "int")
	{
		intelligence = lowScores[lowIndex];
		lowIndex--;
	}
	if (getMainAbility1() != "wis" && getMainAbility2() != "wis" && getMainAbility3() != "wis")
	{
		wisdom = lowScores[lowIndex];
		lowIndex--;
	}
	if (getMainAbility1() != "cha" && getMainAbility2() != "cha" && getMainAbility3() != "cha")
	{
		charisma = lowScores[lowIndex];
		lowIndex--;
	}
}

void Character::initializeStats()
{
	maxHealth = getHitDie();
	maxHealth += rad->calculateModifier(constitution);
	for (int i = 0; i < calculateLevel() - 1; ++i)
	{
		maxHealth += rad->d(getHitDie());
		maxHealth += rad->calculateModifier(constitution);
	}
	health = maxHealth;
	energy = getMaxEnergy();
}

void Character::initializeItems()
{
	
}

void Character::initializeSpells()
{
	/*if (role->getName() == "Mage")
	{
		spells.push_back(new Spell(rad, "Burning Hands"));
	}*/
}

void Character::addItem(Item* item)
{
	items.push_back(item);
}

void Character::addSpell(Spell* spell)
{
	spells.push_back(spell);
}

bool Character::learnSpell(Spell* spell)
{
	/*if (rad->d(20) + getLore() >= (15 + spell->getLevel()))
	{
		spells.push_back(spell);
		setMessage(name + " learned " + spell->getName() + ".");
		return true;
	}
	
	setMessage(name + " failed to learn " + spell->getName() + ".");*/
	return false;
}

void Character::showCharacterSheet()
{
	vector<string> sheet;
	sheet.push_back(name);
	sheet.push_back("Level " + rad->intToStr(calculateLevel()) + " " + getRole());
	sheet.push_back("XP: " + rad->intToStr(getXP()));
	if (size == SIZE_TINY)
		sheet.push_back("Size Category: Tiny");
	else if (size == SIZE_SMALL)
		sheet.push_back("Size Category: Small");
	else if (size == SIZE_MEDIUM)
		sheet.push_back("Size Category: Medium");
	else if (size == SIZE_LARGE)
		sheet.push_back("Size Category: Large");
	else if (size == SIZE_HUGE)
		sheet.push_back("Size Category: Huge");
	sheet.push_back("");
	sheet.push_back("Ability Scores (Modifiers):");
	sheet.push_back("Strength: " + rad->intToStr(strength) + " (" + rad->intToStr(rad->calculateModifier(strength)) + ")");
	sheet.push_back("Dexterity: " + rad->intToStr(dexterity) + " (" + rad->intToStr(rad->calculateModifier(dexterity)) + ")");
	sheet.push_back("Constitution: " + rad->intToStr(constitution) + " (" + rad->intToStr(rad->calculateModifier(constitution)) + ")");
	sheet.push_back("Intelligence: " + rad->intToStr(intelligence) + " (" + rad->intToStr(rad->calculateModifier(intelligence)) + ")");
	sheet.push_back("Wisdom: " + rad->intToStr(wisdom) + " (" + rad->intToStr(rad->calculateModifier(wisdom)) + ")");
	sheet.push_back("Charisma: " + rad->intToStr(charisma) + " (" + rad->intToStr(rad->calculateModifier(charisma)) + ")");
	sheet.push_back("");
	sheet.push_back("Hit Points: " + rad->intToStr(getHealth()) + "/" + rad->intToStr(getMaxHealth()));
	sheet.push_back("Attack Bonus: " + rad->intToStr(getAttackBonus()));
	sheet.push_back("Armor Class: " + rad->intToStr(getArmorClass()));
	sheet.push_back("Fortitude Save: " + rad->intToStr(getFortitude()));
	sheet.push_back("Reflex Save: " + rad->intToStr(getReflex()));
	sheet.push_back("Will Save: " + rad->intToStr(getWill()));
	sheet.push_back("");
	rad->showMenu(sheet, false);
}

void Character::increaseLevel()
{
	/*float healthRatio = health / (maxHealth * 1.0);
	maxHealth += (rad->calculateModifier(constitution) + rad->d(role->getHitDie()));
	health = (int)round(maxHealth * healthRatio);*/
}
