#include "Level.hpp"
#include "Enemies/Bird.hpp"
#include "TrajectoryComponents/CircularTrajectory.hpp"

class Level1: public Level
{
	public:
		Level1(Game &_game): Level(_game) {}

		virtual void doUpdate()
		{
			if(counter == 100)
			{
				game.spawnEnemy(new Bird(Vector2fHelper::Zero, new CircularTrajectory(Vector2f(320, 0), 320, -M_PI, -0.01)));
			}
		}
};
