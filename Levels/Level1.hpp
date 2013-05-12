#include "Level.hpp"
#include "GraphicComponents/GraphicPrimitives/Sprite.hpp"
#include "Enemies/Bird.hpp"
#include "TrajectoryComponents/CircularTrajectory.hpp"
#include "ResourceManager.hpp"

class Level1: public Level
{
	public:
		Level1(Game &_game): Level(_game), bg(ResourceManager::get()->getTexture(LEVEL1_BACKGROUND)) {}

		virtual void doUpdate()
		{
			bg.setPosition(sf::Vector2f(0, Layer::height-1200+counter));
			if(counter == 100)
			{
				game.spawnEnemy(new Bird(Vector2fHelper::Zero, new CircularTrajectory(Vector2f(Layer::width/2, 0), Layer::width/2, -M_PI, -0.01)));
			}
		}

		virtual void draw(Layer *layers) const
		{
			layers[Layer::BACKGROUND].draw(bg);
		}

	private:
		sf::Sprite bg;
		sf::Vector2f pos;
};
