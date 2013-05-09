#ifndef _TRAJECTORY_HPP
#define _TRAJECTORY_HPP

#include <SFML/Graphics.hpp>

class TrajectoryComponent
{
	public:
		TrajectoryComponent() {pos = nullptr;}

		void init(sf::Vector2f &_pos) {pos = &_pos; onInit();}
		virtual void onInit() {};

		virtual void updatePosition() = 0;
	protected:
		sf::Vector2f *pos;
};

#endif
