#include "ResourceManager.hpp"
#include "Debug.hpp"
#include "GraphicPrimitiveSFML.hpp"

class Sprite: public GraphicPrimitiveSFMLSprite
{
	public:
		Sprite(TextureResource res, sf::Vector2f &pos): GraphicPrimitiveSFMLSprite(sprite), pos(pos)
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

		virtual float getRadius()
		{
			return (sprite.getLocalBounds().width > sprite.getLocalBounds().height ? sprite.getLocalBounds().height : sprite.getLocalBounds().width)/2;
		}

		virtual void draw(Layer *layers) const
		{
			layers[Layer::FOREGROUND].draw(sprite);
		}

	private:
		sf::Vector2f &pos;
		sf::Sprite sprite;
};
