#ifndef _CIRCULARHITBOX_HPP
#define _CIRCULARHITBOX_HPP

#include "../HitboxComponent.hpp"

class CircularHitbox: public HitboxComponent
{
	public:
		CircularHitbox(sf::Vector2f &_pos, sf::Vector2f &_opos, float _R);

		virtual bool collision(HitboxComponent &hb);

		static bool CircleCircleCollision(CircularHitbox &ca, CircularHitbox &cb);

		float R;
};

#endif
