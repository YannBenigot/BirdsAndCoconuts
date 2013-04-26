#ifndef _CONSTANTSPEEDTRAJECTORY_HPP
#define _CONSTANTSPEEDTRAJECTORY_HPP

#include "../TrajectoryComponent.hpp"

class ConstantSpeedTrajectory: public TrajectoryComponent
{
	public:
		ConstantSpeedTrajectory(sf::Vector2f &pos, sf::Vector2f v): TrajectoryComponent(pos), v(v) {};

		virtual void updatePosition()
		{
			pos += v;
		}

	private:
		sf::Vector2f v;
};

#endif
