#ifndef _SHOT_HPP
#define _SHOT_HPP

#include "Thing.hpp"

class Shot: public Thing
{
	virtual void updateCommon()
	{
		if(
				pos.x < -graphicComponent->getRadius() 
				|| pos.x > 640 + graphicComponent->getRadius() 
				|| pos.y < -graphicComponent->getRadius()
				|| pos.y > 480 + graphicComponent->getRadius())
			setMode(DEAD);
	}
};

#endif
