#include "RectangularHitbox.hpp"

bool RectangularHitbox::RectangleCircleCollision(RectangularHitbox &r, CircularHitbox &c)
{
	return true;
}

bool RectangularHitbox::collision(HitboxComponent &hb)
{
	if(typeid(hb) == typeid(CircularHitbox))
		return RectangleCircleCollision(*this, (CircularHitbox &) hb);
	else if(typeid(hb) == typeid(RectangularHitbox))
		//return RectangleRectangleCollision(*this, (RectangularHitbox &) hb);
		return true;
	else
		return hb.collision(*this);
}
