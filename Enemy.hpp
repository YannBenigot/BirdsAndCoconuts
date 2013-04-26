#ifndef _ENEMY_HPP
#define _ENEMY_HPP

#include "Thing.hpp"
#include "Debug.hpp"

class Enemy: public Thing
{
	public:
		Enemy(int _life): life(_life) {};

		virtual void onCollision(Thing &thing)
		{
			life -= thing.getDamage();
			if(life <= 0)
				setMode(DYING);
		}

	protected:
		int life;
};

#endif
