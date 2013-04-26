#include "AnimatedSprite.hpp"
#include <iostream>
#include "Debug.hpp"

const int SHADOW_X = 5, SHADOW_Y = 5;

// Shadows are projected as if there was a light in the center of the screen.
// Not a good idea.
//#define SHADOW_X (x-320)/10
//#define SHADOW_Y (y-240)/10

AnimatedSprite::AnimatedSprite(AnimatedSpriteBaseResource asBaseRes, sf::Vector2f &pos, int speed, bool loop): speed(speed), counter(speed), mode(0), pos(pos), asbase(ResourceManager::get()->getASBase(asBaseRes)), loop(loop)
{
	setTexture(asbase.texture, true);

	setOrigin(asbase.width/2, asbase.height/2);

	flipped = false;
	endReached = false;
	counter = speed;
	mode = 0;
	currentRect = asbase.rects[mode].begin();
	setTextureRect(*currentRect);
}

AnimatedSprite::~AnimatedSprite()
{
}

void AnimatedSprite::update()
{
	setPosition(pos);
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
		setTextureRect(*currentRect);
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
	setTextureRect(*currentRect);
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
		setScale(-1, 1);
	}
	else
	{
		setScale(1, 1);
	}
}
