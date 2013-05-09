#include "Vector.hpp"

sf::Vector2f Vector2::Zero(0, 0);

sf::Vector2f Vector2::radial(float angle)
{
	return sf::Vector2f(cos(angle), sin(angle));
}

