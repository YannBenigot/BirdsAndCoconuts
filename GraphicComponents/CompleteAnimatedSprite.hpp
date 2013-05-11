#ifndef _COMPLETEANIMATEDSPRITE_HPP
#define _COMPLETEANIMATEDSPRITE_HPP

#include "GraphicComponentEmbeddedTransformable.hpp"
#include "GraphicPrimitives/AnimatedSprite.hpp"

class CompleteAnimatedSprite: public GraphicComponentEmbeddedTransformable
{
	public:
		CompleteAnimatedSprite(AnimatedSpriteBaseResource res, Vector2f &pos, int speed): asprite(AnimatedSprite(res, pos, speed)), GraphicComponentEmbeddedTransformable(asprite) {};
		virtual ~CompleteAnimatedSprite() {};
		virtual void updateCommon() {asprite.update();};

		virtual void onSetAppearing() {asprite.setMode(0, false);};
		virtual void onSetAlive() {asprite.setMode(1, true);};
		virtual void onSetDying() {asprite.setMode(2, false);};
		virtual bool updateAppearing() {return asprite.isEndReached();}
		virtual bool updateDying() {return asprite.isEndReached();}
		
		AnimatedSprite asprite;
	private:
};

//CompleteAnimatedSprite::CompleteAnimatedSprite(AnimatedSpriteBaseRessource res, Vector2f &pos, int speed): asprite(AnimatedSprite(res, pos, speed)) {};

#endif
