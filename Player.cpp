#include <stdlib.h>
#include "Game.hpp"
#include "RadialShot.hpp"
#include "TrajectoryComponents/PlayerTrajectory.hpp"
#include "HitboxComponents/CircularHitbox.hpp"

#include <time.h>

Player::Player(Game &game): caSprite(CompleteAnimatedSprite(ASBASE_TEST, pos, 10)), game(game)
{
	pos.x = Layer::width/2; pos.y = Layer::height/2;
	setGraphicComponent(&caSprite);
	setHitboxComponent(new CircularHitbox(pos, opos, 1));
	srand(time(NULL));
	setTrajectoryComponent(new PlayerTrajectory());
	weaponCooldown = 0;
	setMode(APPEARING);
}

void Player::updateAlive()
{
	if(weaponCooldown > 0)
		weaponCooldown--;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && weaponCooldown == 0)
	{
		game.spawnFriendlyShot(new RadialShot(pos, 20.0f*Vector2f(-0.71, -0.71), SHOT_BLUE));
		game.spawnFriendlyShot(new RadialShot(pos, 20.0f*Vector2f( 0   , -1   ), SHOT_BLUE));
		game.spawnFriendlyShot(new RadialShot(pos, 20.0f*Vector2f( 0.71, -0.71), SHOT_BLUE));
		weaponCooldown = 3;
	}
//	if(rand()%2 == 0) game.spawnFriendlyShot(new RadialShot(pos, Vector2f(rand()%60-30, rand()%60-30), SHOT_BLUE));
//	if(rand()%2 == 0) game.spawnEnemyShot(new RadialShot(Vector2f(320, 400), Vector2f(rand()%60-30, rand()%60-30)));
}
