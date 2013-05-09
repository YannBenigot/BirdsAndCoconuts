#include <stdlib.h>
#include "Game.hpp"
#include "RadialShot.hpp"
#include "TrajectoryComponents/PlayerTrajectory.hpp"
#include "HitboxComponents/CircularHitbox.hpp"

#include <time.h>

Player::Player(Game &game): caSprite(CompleteAnimatedSprite(ASBASE_TEST, pos, 10)), game(game)
{
	pos.x = 320; pos.y = 240;
	setGraphicComponent(&caSprite);
	setHitboxComponent(new CircularHitbox(pos, opos, 1));
	srand(time(NULL));
	setTrajectoryComponent(new PlayerTrajectory());
	setMode(APPEARING);
}

void Player::manageInput(sf::Event &ev)
{
}

void Player::updateAlive()
{
//	if(rand()%2 == 0) game.spawnFriendlyShot(new RadialShot(pos, sf::Vector2f(rand()%60-30, rand()%60-30), SHOT_BLUE));
//	if(rand()%2 == 0) game.spawnEnemyShot(new RadialShot(sf::Vector2f(320, 400), sf::Vector2f(rand()%60-30, rand()%60-30)));
}
