#ifndef SPRITE_H
#define SPRITE_H

#include "GraphicPrimitiveSFML.hpp"
#include "ResourceManager.hpp"

class AnimatedSprite : public GraphicPrimitiveSFMLSprite
{
	public:
		AnimatedSprite(AnimatedSpriteBaseResource asBaseRes, Vector2f &pos, int speed, bool loop=true);
		~AnimatedSprite();

		void setSpeed(int speed);
		void setMode(int mode, bool loop = true);
		void flip();
		void setFlip(bool flipped);
		bool isEndReached() {return endReached;};

		virtual float getRadius() {return radius;}
		virtual void update();
		virtual void draw(Layer *layers) const;

	private:
		sf::Sprite sprite;
		float radius;

		int mode;
		int speed;
		int counter;
		Vector2f &pos;

		bool flipped;
		bool loop;
		bool endReached;
		AnimatedSpriteBase &asbase;
		std::list<sf::IntRect>::iterator currentRect;
};

#endif
