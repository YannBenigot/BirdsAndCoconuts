#include <math.h>
#include "Thing.hpp"
#include "GraphicComponents/CompleteAnimatedSprite.hpp"

#include "RadialShot.hpp"

#include "ResourceManager.hpp"

class TestThing: public Thing
{
	public:
		int counter;
		TestThing() 
		{
			hitboxComponent = new CircularHitbox(pos, opos, 1);
			graphicComponent = new CompleteAnimatedSprite(ASBASE_TEST, pos, 10);
			counter = 30;
			t = 0;
			pos.x = 420; pos.y = 240;
			setMode(APPEARING);
		}

		float t;
		virtual void updateCommon()
		{
			t += 0.1;
			pos.x = 320+100*cos(t);
			pos.y = 240+100*sin(t);
		}

		virtual void updateAppearing() {/*counter--; if(counter == 0) setMode(Thing::ALIVE);*/}
		virtual void onSetAlive() {counter = 300;}
		virtual void updateAlive() {counter--; if(counter == 0) setMode(Thing::DYING);}
		virtual void onSetDying() {counter = 25;}
		virtual void updateDying() {/*counter--; if(counter == 0) ((CompleteAnimatedSprite *) graphicComponent)->asprite.setSpeed(-1);*/}

};

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Test");
	ResourceManager::get()->init();
	TestThing thing;

	RadialShot rs(sf::Vector2f(100, 100), sf::Vector2f(1, 1));

	while(window.isOpen())
	{
		thing.update();
		rs.update();
		rs.printDBG();
		thing.printDBG();
		window.clear(sf::Color(255, 255, 255));
		window.draw(thing);
		window.draw(rs);

		if(rs.collision(thing))
		{
			std::cout << "AREUBEUBEUH COLLISION" << std::endl;
			rs.onCollision(thing);
			thing.onCollision(rs);
		}

		window.display();
		sf::sleep(sf::milliseconds(100));
	}

	return 0;
}
