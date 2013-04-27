#include "TrajectoryComponent.hpp"

class PlayerTrajectory: public TrajectoryComponent
{
	public:
		PlayerTrajectory(sf::Vector2f &pos): TrajectoryComponent(pos) {}

		virtual void updatePosition()
		{
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				pos.x -= 1.0;
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				pos.x += 1.0;
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				pos.y -= 1.0;
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				pos.y += 1.0;
		}
};

