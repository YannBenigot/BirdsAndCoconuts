#include "HitboxComponent.hpp"
#include "CircularHitbox.hpp"

class RectangularHitbox: public HitboxComponent
{
	public:
		RectangularHitbox(Vector2f &_pos, Vector2f &_opos, float _width, float _height);
		virtual bool collision(HitboxComponent &hb);

		static bool RectangleCircleCollision(RectangularHitbox &r, CircularHitbox &c);

	private:
		float width;
		float height;
};


