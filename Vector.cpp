#include "Vector.hpp"

Vector2f Vector2fHelper::Zero(0, 0);

Vector2f Vector2fHelper::radial(float angle)
{
	return Vector2f(cos(angle), sin(angle));
}

