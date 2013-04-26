#ifndef _TRAJECTORY_HPP
#define _TRAJECTORY_HPP

#include <SFML/Graphics.hpp>

class TrajectoryComponent
{
	public:
		TrajectoryComponent(sf::Vector2f &pos): pos(pos) {};
		virtual void updatePosition() = 0;
	protected:
		sf::Vector2f &pos;
};

#endif
