#ifndef _THING_HPP
#define _THING_HPP

#include <SFML/Graphics.hpp>
#include "GraphicComponent.hpp"
#include "HitboxComponent.hpp"
#include "TrajectoryComponent.hpp"
#include "Vector.hpp"
#include "Debug.hpp"

class Thing: public Drawable
{
	public:
		Thing() 
		{
			mode = DEAD; // Should be overwritten by child constructor, using a setMode() call
			updatePosAppearing = true;
			updatePosDying = true;
		}

		void update();
		virtual void updateCommon() {};
		virtual void updateAppearing() {};
		virtual void updateAlive() {};
		virtual void updateDying() {};

		virtual void onSetAppearing() {};
		virtual void onSetAlive() {};
		virtual void onSetDying() {};

		bool collision(Thing &thing) {return (alive() && thing.alive() && hitboxComponent->collision(*(thing.hitboxComponent)));}
		virtual void onCollision(Thing &thing) {};

		virtual int getDamage() {return 0;};

		bool dead() {return mode == DEAD;};
		bool alive() {return mode == ALIVE;};

		HitboxComponent *hitboxComponent;
		GraphicComponent *graphicComponent;
		TrajectoryComponent *trajectoryComponent;

		virtual void draw(Layer *layers) const {if(mode != DEAD) graphicComponent->draw(layers);}

		void printDBG() {DBG(pos << " - " << opos);}
	protected:
		enum Mode {APPEARING, ALIVE, DYING, DEAD};

		void setMode(Mode _mode);

		sf::Vector2f pos;
		sf::Vector2f opos;

		bool updatePosAppearing, updatePosDying;

	private:
		enum Mode mode;
};

#endif
