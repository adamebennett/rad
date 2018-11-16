#include "Spell.h"
#include "Rad.h"
#include "Character.h"
#include "Player.h"

// Constructors and Destructors //

Spell::Spell(Rad* t, string n)
{
	rad = t;
	name = n;
	if (name == "Burning Hands")
	{
		level = 1;
		hasTarget = true;
	}
	else if (name == "Cure Light Wounds")
	{
		level = 1;
		hasTarget = true;
	}
	else {
		level = 10;
		hasTarget = false;
	}
}

Spell::Spell(Rad* t, int l, string n, bool b)
{
	rad = t;
	level = l;
	name = n;
	hasTarget = b;
}

// Functions //

// Getters:

int Spell::getLevel()
{
	return level;
}

string Spell::getName()
{
	return name;
}

bool Spell::getHasTarget()
{
	return hasTarget;
}

int Spell::getDC(Character* caster)
{
	return 10 + level + rad->calculateModifier(caster->getIntelligence());
}

// Misc:

string Spell::spellString(Character* caster)
{
	string s = "";
	s += name + ", Level: " + rad->intToStr(level) + ", DC: " + rad->intToStr(getDC(caster));
	return s;
}

bool Spell::cast(Character* caster, int dx, int dy)
{
	/*if (hasTarget)
	{
		if (dx < -1 || dx > 1 || dy < -1 || dy > 1)
		{
			caster->setMessage("Never mind.");
			return false;
		}
	}
	if (caster->getRole()->getMaxSpellLevel() < level)
	{
		caster->setMessage("You cannot yet cast spells of this level.");
		return false;
	}
	if (caster->getEnergy() < level)
	{
		caster->setMessage("Not enough magic points.");
		return false;
	}
	
	if (spellEffect(caster, dx, dy, getDC(caster), caster->getRole()->getLevel()))
	{
		caster->setEnergy(caster->getEnergy() - level);
		return true;
	}*/
	
	return false;
}

bool Spell::castFromScroll(Character* reader, int dx, int dy)
{
	if (hasTarget)
	{
		if (dx < -1 || dx > 1 || dy < -1 || dy > 1)
		{
			reader->setMessage("Never mind.");
			return false;
		}
	}
	
	if (spellEffect(reader, dx, dy, 10 + level, (level * 2) - 1))
	{
		return true;
	}
	
	return false;
}

bool Spell::spellEffect(Character* caster, int dx, int dy, int dc, int casterLevel)
{
	/*if (name == "Ray of Frost")
	{
		identify(caster);
		int x = caster->getX() + dx;
		int y = caster->getY() + dy;
		rad->castRangedHPSpellAt(caster, x, y, dx, dy, dc, "reflex", rad->d(3), "Cold", true);
	}
	else if (name == "Burning Hands")
	{
		if (dx == 0 && dy == 0)
		{
			caster->setMessage("You cannot cast that spell in this direction.");
			return false;
		}
		identify(caster);
		int x = caster->getX();
		int y = caster->getY();
		vector<Point> area = getArea(3, getAngle(dx, dy) - 45, getAngle(dx, dy) + 45, x, y, false);
		for (int i = 0; i < area.size(); ++i)
		{
			rad->castHPSpellAt(caster, area[i].x, area[i].y, dc, "reflex", rad->numD(min(casterLevel, 5),4), "Fire", true);
		}
	}
	else if (name == "Cure Light Wounds")
	{
		identify(caster);
		int x = caster->getX() + dx;
		int y = caster->getY() + dy;
		rad->castHPSpellAt(caster, x, y, dc, "will harmless", -(rad->d(8) + min(casterLevel, 5)), "Healing", true);
	}*/
	return true;
}

void Spell::identify(Character* caster)
{
	/*if (caster == rad->getPlayer()->getCharacter() || (rad->d(20) + rad->getPlayer()->getCharacter()->getLore()) >= (15 + level))
	{
		rad->getPlayer()->setMessage(caster->getName() + " cast " + name + "!");
	}
	else
	{
		rad->getPlayer()->setMessage(caster->getName() + " cast a spell!");
	}*/
}

int Spell::getAngle(int dx, int dy)
{
	if (dx == 1 && dy == 0)
		return 0;
	if (dx == 1 && dy == 1)
		return 45;
	if (dx == 0 && dy == 1)
		return 90;
	if (dx == -1 && dy == 1)
		return 135;
	if (dx == -1 && dy == 0)
		return 180;
	if (dx == -1 && dy == -1)
		return 225;
	if (dx == 0 && dy == -1)
		return 270;
	if (dx == 1 && dy == -1)
		return 315;
	return 0;
}

vector<Spell::Point> Spell::getArea(int range, int startAngle, int endAngle, int offsetX, int offsetY, bool includeSelf)
{
	vector<Point> area = vector<Point>();
	if (includeSelf)
	{
		Point p;
		p.x = offsetX;
		p.y = offsetY;
		area.push_back(p);
	}
	for (int z = 0; z < range + 1; ++z)
	{
		for (int a = startAngle; a < endAngle; a++)
		{			
			float r = a * (PI / 180.0);
			int x = (int)(round(cos(r)*z));
			int y = (int)(round(sin(r)*z));
			if (x != 0 || y != 0)
			{
				bool alreadyPassed = false;
				for (int i = 0; i < area.size(); ++i)
				{
					if (area[i].x == x + offsetX && area[i].y == y + offsetY)
					{
						alreadyPassed = true;
					}
				}
				if (!alreadyPassed)
				{
					Point p;
					p.x = x + offsetX;
					p.y = y + offsetY;
					area.push_back(p);
				}
			}
		}
	}
	return area;
}