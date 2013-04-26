#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "Debug.hpp"
#include "GraphicComponents/ShotGraphic.hpp"

class Sprite: public sf::Sprite
{
	public:
		Sprite(TextureResource res, sf::Vector2f &pos): pos(pos)
		{
			setTexture(ResourceManager::get()->getTexture(res));
			setOrigin(getLocalBounds().width/2, getLocalBounds().height/2);
			setPosition(pos);
		}

		void update()
		{
			setPosition(pos);
		}

		sf::Color getAverageColor() {return sf::Color(0, 0, 0);}

		void setAlpha(unsigned char a) {sf::Color c = getColor(); c.a = a; setColor(c);}

		float getRadius()
		{
			return (getLocalBounds().width > getLocalBounds().height ? getLocalBounds().height : getLocalBounds().width)/2;
		}

	private:
		sf::Vector2f &pos;
};
