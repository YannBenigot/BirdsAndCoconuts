#ifndef _CONSTANTSPEEDTRAJECTORY_HPP
#define _CONSTANTSPEEDTRAJECTORY_HPP

#include "TrajectoryComponent.hpp"

class ConstantSpeedTrajectory: public TrajectoryComponent
{
	public:
		ConstantSpeedTrajectory(Vector2f v): v(v) {};

		virtual void updatePosition()
		{
			*pos += v;
		}

	private:
		Vector2f v;
};

#endif
