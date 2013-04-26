#include "Shot.hpp"
#include "Sprite.hpp"
#include "Debug.hpp"
#include "TrajectoryComponents/ConstantSpeedTrajectory.hpp"
#include "HitboxComponents/CircularHitbox.hpp"

#include <math.h>

class SimpleShot: public Shot
{
	public:
		SimpleShot(TextureResource res, sf::Vector2f _pos)
		{
			pos = _pos;
			opos = pos;
			graphicComponent = new ShotGraphic<Sprite>(new Sprite(res, pos));
			hitboxComponent = new CircularHitbox(pos, opos, ((ShotGraphic<Sprite> *)graphicComponent)->getRadius());
			setMode(ALIVE);
		}

		virtual void onCollision(Thing &thing) 
		{
			((ShotGraphic<Sprite> *)graphicComponent)->setCollision();
			trajectoryComponent = new ConstantSpeedTrajectory(pos, opos-pos);
			setMode(DYING);
		}

		virtual int getDamage() {return 1;}
};
