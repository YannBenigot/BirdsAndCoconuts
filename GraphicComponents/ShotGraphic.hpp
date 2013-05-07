#include "GraphicComponent.hpp"
#include "Debug.hpp"

class ShotGraphic: public GraphicComponentEmbeddedTransformable
{
	public:
		ShotGraphic(GraphicPrimitive *_graphicPrimitive, int _speed = 5): GraphicComponentEmbeddedTransformable(*_graphicPrimitive)
		{
			graphicPrimitive = _graphicPrimitive;
			speed = _speed;
			counter = _speed;
			collision = false;
		}

		virtual ~ShotGraphic()
		{
			delete graphicPrimitive;
		}

		virtual void updateCommon() 
		{
			graphicPrimitive->update();
		}

		void setCollision() {collision = true;}

		virtual void onSetAlive()
		{
			counter = 0;
		}

		virtual void onSetDying()
		{
			counter = speed;
		}

		virtual bool updateDying()
		{
			float ratio = ((float)speed-counter)/speed;
			counter--;
			setOpacity(1-ratio);
			if(counter < 0)
				return true;
			return false;
		}

		GraphicPrimitive *getGraphicPrimitive() {return graphicPrimitive;}

	private:
		int speed;
		int counter;
		bool collision;
		GraphicPrimitive *graphicPrimitive;
};


