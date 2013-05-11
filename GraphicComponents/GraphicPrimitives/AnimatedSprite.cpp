#include "AnimatedSprite.hpp"
#include <iostream>
#include "Debug.hpp"

const int SHADOW_X = 5, SHADOW_Y = 5;

// Shadows are projected as if there was a light in the center of the screen.
// Not a good idea.
//#define SHADOW_X (x-320)/10
//#define SHADOW_Y (y-240)/10

AnimatedSprite::AnimatedSprite(AnimatedSpriteBaseResource asBaseRes, Vector2f &pos, int speed, bool loop): GraphicPrimitiveSFMLSprite(sprite), speed(speed), counter(speed), mode(0), pos(pos), asbase(ResourceManager::get()->getASBase(asBaseRes)), loop(loop)
{
	sprite.setTexture(asbase.texture, true);

	sprite.setOrigin(asbase.width/2, asbase.height/2);

	flipped = false;
	endReached = false;
	counter = speed;
	mode = 0;
	currentRect = asbase.rects[mode].begin();
	sprite.setTextureRect(*currentRect);
}

AnimatedSprite::~AnimatedSprite()
{
}

void AnimatedSprite::update()
{
	sprite.setPosition(pos);
	if(speed < 0) return;
	counter--;
	if(counter < 0)
	{
		counter = speed;
		currentRect++;
		if(currentRect == asbase.rects[mode].end())
		{
			if(loop)
				currentRect = asbase.rects[mode].begin();
			else if(!endReached)
			{
				endReached = true;
				currentRect--;
			}
		}
		sprite.setTextureRect(*currentRect);
	}
}

void AnimatedSprite::setSpeed(int _speed)
{
	speed = _speed;
}

void AnimatedSprite::setMode(int _mode, bool _loop)
{
	mode = _mode;
	currentRect = asbase.rects[mode].begin();
	sprite.setTextureRect(*currentRect);
	endReached = false;
	loop = _loop;
}

void AnimatedSprite::flip()
{
	setFlip(!flipped);
}

void AnimatedSprite::setFlip(bool _flipped)
{
	flipped = _flipped;
	if(flipped)
	{
		sprite.setScale(-1, 1);
	}
	else
	{
		sprite.setScale(1, 1);
	}
}

void AnimatedSprite::draw(Layer *layers) const
{
	layers[Layer::FOREGROUND].draw(sprite);
}
