#ifndef _SHOT_HPP
#define _SHOT_HPP

#include "Thing.hpp"

class Shot: public Thing
{
	virtual void updateCommon()
	{
		if(
				pos.x < -getGraphicComponent()->getRadius() 
				|| pos.x > 640 + getGraphicComponent()->getRadius() 
				|| pos.y < -getGraphicComponent()->getRadius()
				|| pos.y > 480 + getGraphicComponent()->getRadius())
			setMode(DEAD);
	}
};

#endif
