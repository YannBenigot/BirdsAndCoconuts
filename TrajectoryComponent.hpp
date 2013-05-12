#ifndef _TRAJECTORY_HPP
#define _TRAJECTORY_HPP

#include <Vector.hpp>

class TrajectoryComponent
{
	public:
		TrajectoryComponent() {pos = nullptr;}

		void init(Vector2f &_pos) {pos = &_pos; onInit();}
		virtual void onInit() {};

		virtual void updatePosition() = 0;
	protected:
		Vector2f *pos;
};

#endif
