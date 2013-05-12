#ifndef _GRAPHICS_HPP
#define _GRAPHICS_HPP

#ifndef M_PI
#define M_PI 3.14159265358979323
#endif

#include <SFML/Graphics.hpp>
#include "Vector.hpp"

class Layer: public sf::RenderTexture
{
	public:
		enum GameLayerId
		{
			BACKGROUND,
			SHADOWS,
			FOREGROUND,
			COUNT
		};

		Layer();

		static const int width, height;
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
		virtual void scale(float factor) {scale(Vector2f(factor, factor));};
		virtual void scale(Vector2f factor) = 0;
		virtual void setOpacity(float ratio) = 0;
};

#endif
