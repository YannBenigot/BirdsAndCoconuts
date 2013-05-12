#include "Enemy.hpp"

void Enemy::onCollision(Thing &thing)
{
	life -= thing.getDamage();
	if(life <= 0)
		setMode(DYING);
}