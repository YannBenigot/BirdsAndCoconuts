#ifndef _HITBOX_HPP
#define _HITBOX_HPP

#include "Vector.hpp"

class HitboxComponent
{
	public:
		HitboxComponent(Vector2f &_pos, Vector2f &_opos);

		virtual void update() {};

		virtual bool collision(HitboxComponent &hb) = 0;
		static float GetMinDist(HitboxComponent &ha, HitboxComponent &hb);
		static float GetColTime(HitboxComponent &ha, HitboxComponent &hb);

	protected:
		Vector2f &pos, &opos;
};

#endif
