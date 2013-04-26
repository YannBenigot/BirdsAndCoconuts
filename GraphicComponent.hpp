#ifndef _GRAPHICCOMPONENT_H
#define _GRAPHICCOMPONENT_H

#include <SFML/Graphics.hpp>

class GraphicComponent: public sf::Drawable
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
};

#endif
