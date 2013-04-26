#include "../GraphicComponent.hpp"
#include "../Debug.hpp"

template<class G> class ShotGraphic: public GraphicComponent
{
	public:
		ShotGraphic(G *_g, int _speed = 5)
		{
			g = _g;
			speed = _speed;
			R = g->getRadius();
			circle.setFillColor(g->getAverageColor());
			counter = _speed;
			collision = false;
		}

		virtual ~ShotGraphic()
		{
			delete g;
		}

		virtual void updateCommon() 
		{
			g->update();
		}

		void setCollision() {collision = true;}

		void setAlpha(unsigned char a)
		{
			sf::Color c = circle.getFillColor();
			c.a = a;
			circle.setFillColor(c);
			g->setAlpha(a);
		}

		/*virtual void updateAppearing()
		{
			circle.setPosition(g->getPosition());
			if(counter > speed/2)
			{
				float ratio = 1-((float)counter - speed/2)*2/speed;
				circle.setRadius(ratio*R);
				circle.setAlpha(ratio*255);
			}
			else
			{
				float ratio = ((float)speed/2-counter)*2/speed;
				circle.setRadius((1+ratio)*R);
				circle.setAlpha(ratio*255);
			}
			counter--;
			if(counter < 0)
				setMode(ALIVE);
		}*/

		virtual void onSetAlive()
		{
			counter = 0;
		}

		virtual void onSetDying()
		{
			counter = speed;
		}

		virtual bool updateDying()
		{
			float ratio = ((float)speed-counter)/speed;
			counter--;
/*			if(collision)
			{
				int nR = ratio*R;
				circle.setRadius(nR);
				circle.setOrigin(nR/2, nR/2);
				circle.setPosition(g->getPosition());
				setAlpha((1-ratio)*255);
			}
			else
			{
				g->setAlpha((1-ratio)*255);
			}*/
			setAlpha((1-ratio)*255);
			if(counter < 0)
				return true;
			return false;
		}

		virtual float getRadius() {return g->getRadius();}

		G *getG() {return g;}

	protected:
		void draw(sf::RenderTarget &target, sf::RenderStates states) const
		{
			if(counter != 0)
				target.draw(circle);
			target.draw(*g);
		}

	private:
		sf::CircleShape circle;
		int speed;
		int counter;
		int R;
		bool collision;
		G *g;
};


