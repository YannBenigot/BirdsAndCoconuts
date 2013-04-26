#ifndef _GRAPHICPRIMITIVE_HPP
#define _GRAPHICPRIMITIVE_HPP

#include <SFML/Graphics.hpp>

class GraphicPrimitive: public sf::Drawable
{
	public:
		virtual float getRadius() = 0;
		virtual void setAlpha(unsigned char c) = 0;
		virtual void update() {}
//		virtual sf::Color getAverageColor() = 0;
	protected:
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;
};

#endif
