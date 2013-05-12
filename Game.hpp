#ifndef _GAME_HPP
#define _GAME_HPP

#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.hpp"
#include "Shot.hpp"
#include "Enemy.hpp"
#include "Graphics.hpp"
#include "Level.hpp"

class Game: public sf::Drawable
{
	public:
		Game();
		void manageInput(sf::Event &ev);
		void update();

		void spawnEnemy(Enemy *enemy) {enemies.push_back(enemy);};
		void spawnEnemyShot(Shot *shot) {enemyShots.push_back(shot);};
		void spawnFriendlyShot(Shot *shot) {playerShots.push_back(shot);};

	protected:
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	private:
		Layer *layers;
		sf::Sprite *sprites;

		/* HUD, to be replaced by HUD class */
		sf::Texture hudTex;
		sf::Sprite hud;

		Level *level;

		Player player;

		std::list<Enemy *> enemies;
		std::list<Shot *> enemyShots;
		std::list<Shot *> playerShots;
};

#endif
