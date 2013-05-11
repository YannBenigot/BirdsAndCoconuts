#include "Enemy.hpp"
#include "GraphicComponents/CompleteAnimatedSprite.hpp"
#include "HitboxComponents/CircularHitbox.hpp"
#include "Debug.hpp"

class Bird: public Enemy
{
	public:
		Bird(Vector2f _pos, TrajectoryComponent *trajectoryComponent): Enemy(100)
		{
			setGraphicComponent(new CompleteAnimatedSprite(ASBASE_TEST, pos, 10));
			setHitboxComponent(new CircularHitbox(pos, opos, getGraphicComponent()->getRadius()));
			setTrajectoryComponent(trajectoryComponent);
			setMode(ALIVE);
		}
};


