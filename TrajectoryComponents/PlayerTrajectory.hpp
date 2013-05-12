#include "TrajectoryComponent.hpp"

class PlayerTrajectory: public TrajectoryComponent
{
	public:
		virtual void updatePosition();

	private:
		static const float delta;
};

