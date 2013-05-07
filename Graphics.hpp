#ifndef _GRAPHICS_HPP
#define _GRAPHICS_HPP

#include <SFML/Graphics.hpp>

class Layer: public sf::RenderTexture
{
	public:
		enum Id
		{
			BACKGROUND,
			SHADOWS,
			FOREGROUND,
			HUD,
			COUNT
		};
};

class Drawable
{
	public:
		virtual float getRadius() {return 0;};
		virtual void draw(Layer *layers) const = 0;
};

class Transformable: public Drawable
{
	public:
		virtual void rotate(float angle) = 0;
		virtual void scale(float factor) {scale(sf::Vector2f(factor, factor));};
		virtual void scale(sf::Vector2f factor) = 0;
		virtual void setOpacity(float ratio) = 0;
};

#endif
