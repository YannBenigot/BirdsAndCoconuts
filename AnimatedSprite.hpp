#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"

class AnimatedSprite : public sf::Sprite
{
	public:
		AnimatedSprite(AnimatedSpriteBaseResource asBaseRes, sf::Vector2f &pos, int speed, bool loop=true);
		~AnimatedSprite();
		void update();
		void setSpeed(int speed);
		void setMode(int mode, bool loop = true);
		void flip();
		void setFlip(bool flipped);
		bool isEndReached() {return endReached;};

	private:
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
