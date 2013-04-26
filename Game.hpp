#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Shot.hpp"

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
//		Level level;
		Player player;

		std::list<Enemy *> enemies;
		std::list<Shot *> enemyShots;
		std::list<Shot *> playerShots;
};