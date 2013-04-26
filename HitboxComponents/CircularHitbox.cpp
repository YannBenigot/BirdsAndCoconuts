#include "../Vector.hpp"
#include "CircularHitbox.hpp"

CircularHitbox::CircularHitbox(sf::Vector2f &_pos, sf::Vector2f &_opos, float _R): HitboxComponent(_pos, _opos), R(_R)
{
}

bool CircularHitbox::collision(HitboxComponent &hb)
{
	if(typeid(hb) == typeid(CircularHitbox))
		return CircleCircleCollision(*this, (CircularHitbox &) hb);
	else
		return hb.collision(*this);
}

bool CircularHitbox::CircleCircleCollision(CircularHitbox &ca, CircularHitbox &cb)
{
	//DBG("CCCol -> MD = " << GetMinDist(ca, cb) << " - sqRR = " << squared(ca.R+cb.R));
	return GetMinDist(ca, cb) < squared(ca.R+cb.R);
}


