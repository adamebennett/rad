#ifndef TILE_H
#define TILE_H

#include <string>
#include <vector>
#include <curses.h>
#include <cmath>

#include "Graphic.h"

using namespace std;

class Tile
{
	// Members //
	
	protected:
		Graphic* graphic;
		bool visible;
		bool revealed;
		
	// Constructors and Destructors //
	
	public:
		Tile();
		
	// Functions //
		
	public:
		// Getters:
		Graphic getGraphic() const;
		bool getVisible();
		bool getRevealed();
		
		// Setters:
		void setVisible(bool);
		void setRevealed(bool);
		
		// Misc
		virtual bool isSolid();
		virtual string getName();
};

#endif