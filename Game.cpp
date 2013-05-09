#include "Game.hpp"
#include "SimpleEnemy.hpp"
#include "Debug.hpp"
#include "Levels/Level1.hpp"

Game::Game(): player(Player(*this))
{
	layers = new Layer[Layer::COUNT]();
	sprites = new sf::Sprite[Layer::COUNT]();

	for(int i=0; i<Layer::COUNT; i++)
	{
		layers[i].create(640, 480);
		sprites[i].setTexture(layers[i].getTexture());
	}

	level = new Level1(*this);
}

void Game::manageInput(sf::Event &ev)
{
	player.manageInput(ev);
}

template<class T> void cleanup(std::list<T *> &l)
{
	for(auto it = l.begin(); it != l.end();)
	{
		T *t = *it;
		if(t->dead())
		{
			it = l.erase(it);
			delete t;
		}
		else
			it++;
	}
}


void Game::update()
{
	level->update();
	player.update();

//	if(rand()%5 == 0) 
//		spawnEnemy(new SimpleEnemy(*this, ASBASE_TEST, sf::Vector2f(320, 300), sf::Vector2f(10, 0), 100, 10, 10));

	for(auto it = enemyShots.begin(); it != enemyShots.end(); it++)
	{
		Shot &shot = **it;
		shot.update();
		if(shot.collision(player))
		{
			player.onCollision(shot);
			shot.onCollision(player);
		}
	}

	for(auto it = playerShots.begin(); it != playerShots.end(); it++)
	{
		Shot &shot = **it;
		shot.update();
		for(auto it = enemies.begin(); it != enemies.end(); it++)
		{
			Enemy &enemy = **it;
			if(shot.collision(enemy))
			{
				enemy.onCollision(shot);
				shot.onCollision(enemy);
			}
		}

		/* To remove */
		for(auto it = enemyShots.begin(); it != enemyShots.end(); it++)
		{
			Shot &enShot = **it;
			if(enShot.collision(shot))
			{
				shot.onCollision(enShot);
				enShot.onCollision(shot);
			}
		}
	}

	for(auto it = enemies.begin(); it != enemies.end(); it++)
		(*it)->update();

	// Cleanup
	cleanup<Shot>(enemyShots);
	cleanup<Enemy>(enemies);
	cleanup<Shot>(playerShots);
}

template<class T> void listDraw (const std::list<T *> &l, Layer *layers)
{
	for(auto it = l.begin(); it != l.end(); it++)
		(**it).draw(layers);
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
//	level.draw(target, states);
	for(int i=0; i<Layer::COUNT; i++)
		layers[i].clear(sf::Color(255, 255, 255, 0));
	layers[Layer::BACKGROUND].clear(sf::Color(128, 128, 128, 255));
	listDraw<Shot>(playerShots, layers);
	listDraw<Shot>(enemyShots, layers);
	listDraw<Enemy>(enemies, layers);
	player.draw(layers);
	for(int i=0; i<Layer::COUNT; i++)
	{
		layers[i].display();
		target.draw(sprites[i]);
	}
}
