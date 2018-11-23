#ifndef THEURGE_H
#define THEURGE_H

#include "Character.h"

class Rad;
class Actor;

using namespace std;

class Theurge: public Character {
		
	// Constructors and Destructors //
	
	public:
		Theurge(Rad*, Actor*);
		~Theurge();

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
