#include "Enemy.hpp"
#include "GraphicComponents/CompleteAnimatedSprite.hpp"
#include "HitboxComponents/CircularHitbox.hpp"
#include "TrajectoryComponents/ConstantSpeedTrajectory.hpp"
#include "RadialShot.hpp"
#include "Debug.hpp"

class SimpleEnemy: public Enemy
{
	public:
		SimpleEnemy(Game &_game, AnimatedSpriteBaseResource res, Vector2f _pos, Vector2f v, int life, int _shotRate, int spriteSpeed): Enemy(game, life)
		{
			pos = _pos;
			opos = _pos;
			setGraphicComponent(new CompleteAnimatedSprite(res, pos, spriteSpeed));
			setHitboxComponent(new CircularHitbox(pos, opos, getGraphicComponent()->getRadius()));
			setTrajectoryComponent(new ConstantSpeedTrajectory(v));
			shotRate = _shotRate;
			shotRateCounter = shotRate;
			setMode(ALIVE);
		}
	
		virtual void updateAlive()
		{
			shotRateCounter--;
			if(shotRateCounter < 0)
			{
				game.spawnEnemyShot(new RadialShot(pos, Vector2f(pos.y-opos.y, opos.x-pos.x)));
				shotRateCounter = shotRate;
			}
		}

	private:
		int shotRate, shotRateCounter;
};

