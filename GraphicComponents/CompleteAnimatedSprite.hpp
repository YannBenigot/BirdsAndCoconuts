#ifndef _COMPLETEANIMATEDSPRITE_HPP
#define _COMPLETEANIMATEDSPRITE_HPP

#include "GraphicComponent.hpp"
#include "GraphicPrimitives/AnimatedSprite.hpp"

class CompleteAnimatedSprite: public GraphicComponent
{
	public:
		CompleteAnimatedSprite(AnimatedSpriteBaseResource res, sf::Vector2f &pos, int speed): asprite(AnimatedSprite(res, pos, speed)) {};
		virtual ~CompleteAnimatedSprite() {};
		virtual void updateCommon() {asprite.update();};

		virtual void onSetAppearing() {asprite.setMode(0, false);};
		virtual void onSetAlive() {asprite.setMode(1, true);};
		virtual void onSetDying() {asprite.setMode(2, false);};
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {target.draw(asprite, states);}
		virtual bool updateAppearing() {return asprite.isEndReached();}
		virtual bool updateDying() {return asprite.isEndReached();}
		AnimatedSprite asprite;
		
		virtual float getRadius() {return 0;};
	private:
};

//CompleteAnimatedSprite::CompleteAnimatedSprite(AnimatedSpriteBaseRessource res, sf::Vector2f &pos, int speed): asprite(AnimatedSprite(res, pos, speed)) {};

#endif
