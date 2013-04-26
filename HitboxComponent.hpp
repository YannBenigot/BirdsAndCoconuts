#ifndef _HITBOX_HPP
#define _HITBOX_HPP

#include <SFML/Graphics.hpp>

class HitboxComponent
{
	public:
		HitboxComponent(sf::Vector2f &_pos, sf::Vector2f &_opos);

		virtual void update() {};

		virtual bool collision(HitboxComponent &hb) = 0;
		static float GetMinDist(HitboxComponent &ha, HitboxComponent &hb);
		static float GetColTime(HitboxComponent &ha, HitboxComponent &hb);

	protected:
		sf::Vector2f &pos, &opos;
};

#endif
