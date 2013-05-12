#ifndef _ENEMY_HPP
#define _ENEMY_HPP

#include "Thing.hpp"
#include "Debug.hpp"

class Game;

class Enemy: public Thing
{
	public:
		Enemy(Game &_game, int _life): life(_life), game(_game) {};

		virtual void onCollision(Thing &thing);

	protected:
		int life;
		Game &game;
};

#endif
