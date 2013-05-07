#ifndef _GRAPHICCOMPONENT_H
#define _GRAPHICCOMPONENT_H

#include "Graphics.hpp"

class GraphicComponent: public Transformable
{
	public:
		virtual ~GraphicComponent() {};
		virtual void updateCommon() {};
		virtual bool updateAppearing() {return false;};
		virtual bool updateAlive() {return false;};
		virtual bool updateDying() {return false;};

		virtual void onSetAppearing() {};
		virtual void onSetAlive() {};
		virtual void onSetDying() {};

		virtual float getRadius() {return 0;};

		// Inherited
		virtual void draw(Layer *layers) const = 0;
		virtual void rotate(float angle) = 0;
		virtual void scale(float factor) = 0;
		virtual void scale(sf::Vector2f factor) = 0;

};

#endif
