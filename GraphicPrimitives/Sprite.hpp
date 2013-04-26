#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "Debug.hpp"
#include "GraphicPrimitive.hpp"

class Sprite: public GraphicPrimitive
{
	public:
		Sprite(TextureResource res, sf::Vector2f &pos): pos(pos)
		{
			sprite.setTexture(ResourceManager::get()->getTexture(res));
			sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
			sprite.setPosition(pos);
		}

		void update()
		{
			sprite.setPosition(pos);
		}

		sf::Color getAverageColor() {return sf::Color(0, 0, 0);}

		void setAlpha(unsigned char a) {sf::Color c = sprite.getColor(); c.a = a; sprite.setColor(c);}

		float getRadius()
		{
			return (sprite.getLocalBounds().width > sprite.getLocalBounds().height ? sprite.getLocalBounds().height : sprite.getLocalBounds().width)/2;
		}

	protected:
		void draw(sf::RenderTarget &target, sf::RenderStates states) const {target.draw(sprite, states);}

	private:
		sf::Vector2f &pos;
		sf::Sprite sprite;
};
