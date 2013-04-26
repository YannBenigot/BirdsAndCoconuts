#include <SFML/Window.hpp>
#include "Thing.hpp"
#include "GraphicComponents/CompleteAnimatedSprite.hpp"

class Game;
class Player: public Thing
{
	public:
		Player(Game &game);
		void manageInput(sf::Event &ev);

		virtual void updateAlive();
	private:
		CompleteAnimatedSprite caSprite;
		Game &game;
};
