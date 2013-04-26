#include "HitboxComponent.hpp"

class LineHitbox: public HitboxComponent
{
	public:
		LineHitbox(sf::Vector2f &_pos, sf::Vector2f &_opos, float _L, float &_w, float &_ow);

		virtual bool collision(HitboxComponent &hb);
		static bool CircleLineCollision(CircularHitbox &c, LineHitbox &l);
		static bool LineLineCollision(LineHitbox &la, LineHitbox &lb);

	private:
		float L, &w, &ow;
};


