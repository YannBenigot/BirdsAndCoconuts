#include "Game.hpp"

int main(void)
{
	ResourceManager::get()->init();

	Game game;

	sf::RenderWindow window(sf::VideoMode(640, 480), "Test");

	while(window.isOpen())
	{
		sf::Event ev;
		while(window.pollEvent(ev))
		{
			game.manageInput(ev);
		}

		game.update();

		window.clear(sf::Color(100, 100, 100));
		window.draw(game);
		window.display();
		sf::sleep(sf::milliseconds(20));
	}

	return 0;
}
