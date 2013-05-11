#ifndef _GRAPHICPRIMITIVESFML_HPP
#define _GRAPHICPRIMITIVESFML_HPP

#include "GraphicComponents/GraphicPrimitive.hpp"
#include <SFML/Graphics.hpp>

class GraphicPrimitiveSFMLTransformable: public GraphicPrimitive
{
	private:
		sf::Transformable *transformable;

	public:
		GraphicPrimitiveSFMLTransformable(sf::Transformable &transformable): transformable(&transformable) {}

		virtual void rotate(float angle) {transformable->setRotation(angle);};
		virtual void scale(Vector2f factor) {transformable->setScale(factor);};
};

class GraphicPrimitiveSFMLSprite: public GraphicPrimitiveSFMLTransformable
{
	private:
		sf::Sprite *sprite;

	public:
		GraphicPrimitiveSFMLSprite(sf::Sprite _sprite): sprite(&_sprite), GraphicPrimitiveSFMLTransformable(*sprite) {};
		virtual void setOpacity(float ratio) {sf::Color c = sprite->getColor(); c.a = ratio * 255; sprite->setColor(c);}
};

#endif
