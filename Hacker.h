#ifndef TECHNICIAN_H
#define TECHNICIAN_H

#include "Character.h"

class Rad;
class Actor;

using namespace std;

class Hacker: public Character {
		
	// Constructors and Destructors //
	
	public:
		Hacker(Rad*, Actor*);
		~Hacker();

	// Getters:
	
		virtual string getRole();
		virtual int getBAB();		
		virtual int getHitDie();
		virtual int getFortitude();
		virtual int getReflex();
		virtual int getWill();
		virtual string getMainAbility1();
		virtual string getMainAbility2();
		virtual string getMainAbility3();
		virtual void initializeItems();
};

#endif
