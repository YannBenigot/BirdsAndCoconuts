#include "../HitboxComponent.hpp"
#include "CircularHitbox.hpp"

class RectangularHitbox: public HitboxComponent
{
	public:
		RectangularHitbox(sf::Vector2f &_pos, sf::Vector2f &_opos, float _width, float _height);
		virtual bool collision(HitboxComponent &hb);

		static bool RectangleCircleCollision(RectangularHitbox &r, CircularHitbox &c);

	private:
		float width;
		float height;
};


