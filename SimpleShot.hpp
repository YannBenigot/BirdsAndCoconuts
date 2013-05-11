#include "Shot.hpp"
#include "GraphicComponents/GraphicPrimitives/Sprite.hpp"
#include "Debug.hpp"
#include "TrajectoryComponents/ConstantSpeedTrajectory.hpp"
#include "HitboxComponents/CircularHitbox.hpp"
#include "GraphicComponents/ShotGraphic.hpp"

#include <math.h>

class SimpleShot: public Shot
{
	public:
		SimpleShot(TextureResource res, Vector2f _pos)
		{
			pos = _pos;
			opos = pos;
			setGraphicComponent(new ShotGraphic(new Sprite(res, pos)));
			setHitboxComponent(new CircularHitbox(pos, opos, getGraphicComponent()->getRadius()));
			setMode(ALIVE);
		}

		virtual void onCollision(Thing &thing) 
		{
			((ShotGraphic *)getGraphicComponent())->setCollision();
			setTrajectoryComponent(new ConstantSpeedTrajectory(opos-pos));
			setMode(DYING);
		}

		virtual int getDamage() {return 1;}
};
