#include "Enemy.hpp"
#include "GraphicComponents/CompleteAnimatedSprite.hpp"
#include "HitboxComponents/CircularHitbox.hpp"
#include "TrajectoryComponents/ConstantSpeedTrajectory.hpp"
#include "RadialShot.hpp"
#include "Debug.hpp"

class SimpleEnemy: public Enemy
{
	public:
		SimpleEnemy(Game &game, AnimatedSpriteBaseResource res, sf::Vector2f _pos, sf::Vector2f v, int life, int _shotRate, int spriteSpeed): Enemy(life), game(game)
		{
			pos = _pos;
			opos = _pos;
			graphicComponent = new CompleteAnimatedSprite(res, pos, spriteSpeed);
			hitboxComponent = new CircularHitbox(pos, opos, graphicComponent->getRadius());
			trajectoryComponent = new ConstantSpeedTrajectory(pos, v);
			shotRate = _shotRate;
			shotRateCounter = shotRate;
			setMode(ALIVE);
		}
	
		virtual void updateAlive()
		{
			shotRateCounter--;
			if(shotRateCounter < 0)
			{
				game.spawnEnemyShot(new RadialShot(pos, sf::Vector2f(pos.y-opos.y, opos.x-pos.x)));
				shotRateCounter = shotRate;
			}
		}

	private:
		int shotRate, shotRateCounter;
		Game &game;
};

