#ifndef SPRITE_H
#define SPRITE_H

#include "GraphicPrimitiveSFML.hpp"
#include "ResourceManager.hpp"

class AnimatedSprite : public GraphicPrimitiveSFMLSprite
{
	public:
		AnimatedSprite(AnimatedSpriteBaseResource asBaseRes, sf::Vector2f &pos, int speed, bool loop=true);
		~AnimatedSprite();

		void setSpeed(int speed);
		void setMode(int mode, bool loop = true);
		void flip();
		void setFlip(bool flipped);
		bool isEndReached() {return endReached;};

		virtual float getRadius() {return 1;}
		virtual void update();
		virtual void draw(Layer *layers) const;

	private:
		sf::Sprite sprite;

		int mode;
		int speed;
		int counter;
		sf::Vector2f &pos;

		bool flipped;
		bool loop;
		bool endReached;
		AnimatedSpriteBase &asbase;
		std::list<sf::IntRect>::iterator currentRect;
};

#endif