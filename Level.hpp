#include <SFML/Graphics.hpp>

class Level: public sf::Drawable
{
	public:
		Level(Game &game): game(game), counter(0) {};

		Level *update() {counter++; return doUpdate;}

		virtual Level *doUpdate() = 0;

	protected:
		Game &game;
		int counter;
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;
};
			
