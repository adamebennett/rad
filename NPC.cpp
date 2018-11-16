#include "NPC.h"
#include "Rad.h"
#include "Item.h"
#include "Spell.h"
#include "Soldier.h"
#include "Hacker.h"
#include "Psychic.h"

#include <sstream>

// Constructors and Destructors //

NPC::NPC(Rad *t, Character* c, int x, int y, int level)
{
	rad = t;
	target = c;
	busy = 0;
	character = NULL;
	if (level < 4) {
		int role = rad->d(1);
		if (role == 1) {
			character = new Soldier(rad, this);
			character->setGraphic(new Graphic('H', COLOR_WHITE));
			character->setFaction(1);
		}
	}
	if (character == NULL) { // make a default character to avoid crashes (this should ideally never happen)
		character = new Soldier(rad, this);
		character->setGraphic(new Graphic('H', COLOR_WHITE));
	}
	character->setX(x);
	character->setY(y);
}

NPC::~NPC()
{
}

// Functions //

// Getters:

Character* NPC::getCharacter() {
	return character;
}

Character* NPC::getTarget() {
	return target;
}

// Setters:

void NPC::setCharacter(Character* c) {
	character = c;
}

// Misc:

void NPC::control(int placeholder)
{
	if (busy > 0) {
		busy--;
		return;
	}
	controlMovement();
	controlAttack();
}

void NPC::controlMovement()
{
	if (busy > 0) {
		return;
	}
	if (adjacentToTarget()) {
		return;
	}
	int moveRandomly = rad->d(3);
	int mX = 0;
	int mY = 0;
	if (moveRandomly == 1 || target == NULL) {
		mX = rad->d(3) - 2;
		mY = rad->d(3) - 2;
	}
	else {
		if (target->getX() > character->getX()) {
			mX = 1;
		}
		else if (target->getX() < character->getX()) {
			mX = -1;
		}
		if (target->getY() > character->getY()) {
			mY = 1;
		}
		else if (target->getY() < character->getY()) {
			mY = -1;
		}
	}
	character->moveBy(mX, mY);
	busy = ACTION_MOVE;
}

void NPC::controlAttack()
{
	if (busy > 0) {
		return;
	}
	if (adjacentToTarget()) {
		rad->attackAt(target->getX(), target->getY(), character, true);
		busy = ACTION_ATTACK;
		return;
	}
}

bool NPC::adjacentToTarget() {
	if (target == NULL) {
		return false;
	}
	if (abs(target->getX() - character->getX()) <= 1) {
		if (abs(target->getY() - character->getY()) <= 1) {
			return true;
		}
	}
	return false;
}
