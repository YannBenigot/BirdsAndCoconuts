#ifndef _CIRCULARTRAJECTORY_HPP
#define _CIRCULARTRAJECTORY_HPP

#include "TrajectoryComponent.hpp"
#include "Debug.hpp"

class CircularTrajectory: public TrajectoryComponent
{
	public:
		CircularTrajectory(Vector2f _center, float _R, float _initialAngle, float _w): center(_center), R(_R), w(_w), angle(_initialAngle) {};

		virtual void onInit()
		{
			*pos = center + R * Vector2fHelper::radial(angle);
		}

		virtual void updatePosition()
		{
			angle += w;
			*pos = center + R * Vector2fHelper::radial(angle);
		}

	private:
		Vector2f center;
		float R;
		float w;
		float angle;
};

#endif
