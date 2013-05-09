#include "SimpleShot.hpp"
#include "TrajectoryComponents/ConstantSpeedTrajectory.hpp"
#include "Debug.hpp"

class RadialShot: public SimpleShot
{
	public:
		RadialShot(sf::Vector2f _pos, sf::Vector2f v, TextureResource res = SHOT_DEFAULT): SimpleShot(res, _pos), v(v)
		{
//			if(v.x != 0 || v.y != 0) 
//				graphicComponent->rotate(atan2(v.y, v.x));
			setTrajectoryComponent(new ConstantSpeedTrajectory(v));
		};

	private:
		sf::Vector2f v;
};
			
