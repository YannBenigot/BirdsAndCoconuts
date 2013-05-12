#include "PlayerTrajectory.hpp"

const float PlayerTrajectory::delta = 1.0;

void PlayerTrajectory::updatePosition()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		pos->x -= delta;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		pos->x += delta;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		pos->y -= delta;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		pos->y += delta;
}