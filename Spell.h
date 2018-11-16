#ifndef SPELL_H
#define SPELL_H

#include <string>
#include <vector>

class Rad;
class Character;
class Player;

using namespace std;

class Spell
{	
	// struct definitions //
	public:
		struct Point {
			int x;
			int y;
		};
	
	// Members //
	
	protected:
		Rad* rad;
		int level;
		string name;
		bool hasTarget;
		
	// Constructors and Destructors //
	
	public:
		Spell(Rad*, string);
		Spell(Rad*, int, string, bool);
		
	// Functions //
		
	public:
		// Getters:
		int getLevel();
		string getName();
		bool getHasTarget();
		int getDC(Character*);
		
		// Misc:
		string spellString(Character*);
		bool cast(Character*, int, int);
		bool castFromScroll(Character*, int, int);
		int getAngle(int, int);
		vector<Spell::Point> getArea(int, int, int, int, int, bool);
		
	private:
		bool spellEffect(Character*, int, int, int, int);
		void identify(Character*);
};

#endif