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
				game.spawnEnemy(new Bird(Vector2::Zero, new CircularTrajectory(sf::Vector2f(320, 0), 320, -M_PI, -0.01)));
			}
		}
};
