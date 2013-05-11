#include "SimpleShot.hpp"
#include "TrajectoryComponents/ConstantSpeedTrajectory.hpp"
#include "Debug.hpp"

class RadialShot: public SimpleShot
{
	public:
		RadialShot(Vector2f _pos, Vector2f v, TextureResource res = SHOT_DEFAULT): SimpleShot(res, _pos), v(v)
		{
//			if(v.x != 0 || v.y != 0) 
//				graphicComponent->rotate(atan2(v.y, v.x));
			setTrajectoryComponent(new ConstantSpeedTrajectory(v));
		};

	private:
		Vector2f v;
};
			
