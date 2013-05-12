#include "Enemy.hpp"
#include "GraphicComponents/CompleteAnimatedSprite.hpp"
#include "HitboxComponents/CircularHitbox.hpp"
#include "Debug.hpp"

class Bird: public Enemy
{
	public:
		Bird(Game &_game, Vector2f _pos, TrajectoryComponent *trajectoryComponent): Enemy(_game, 100)
		{
			pos = _pos;
			setGraphicComponent(new CompleteAnimatedSprite(ASBASE_TEST, pos, 10));
			setHitboxComponent(new CircularHitbox(pos, opos, getGraphicComponent()->getRadius()));
			setTrajectoryComponent(trajectoryComponent);
			setMode(ALIVE);
		}

		virtual void updateAlive()
		{
			if(rand()%20 == 0)
				game.spawnEnemyShot(new RadialShot(pos, Vector2f(0, 10), SHOT_DEFAULT));
		}
};


