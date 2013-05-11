#ifndef _CIRCULARHITBOX_HPP
#define _CIRCULARHITBOX_HPP

#include "HitboxComponent.hpp"

class CircularHitbox: public HitboxComponent
{
	public:
		CircularHitbox(Vector2f &_pos, Vector2f &_opos, float _R);

		virtual bool collision(HitboxComponent &hb);

		static bool CircleCircleCollision(CircularHitbox &ca, CircularHitbox &cb);

		float R;
};

#endif
