#ifndef _LEVEL_HPP
#define _LEVEL_HPP

#include "Graphics.hpp"

class Game;

class Level: public Drawable
{
	public:
		Level(Game &game): game(game), counter(0) {};

		void update() {counter++; doUpdate();}

		virtual void doUpdate() = 0;

	protected:
		Game &game;
		int counter;
};

#endif
