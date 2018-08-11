#include <iostream>
#include <vector>

#include "Game.h"
#include "AssetManager.h"

using namespace sf;
using namespace std;

Game::Game()
	:win(sf::VideoMode(800, 600), "SFML Window")
{
	win.setFramerateLimit(144);
}

void Game::run()
{
	AssetManager::Load();

	GameObject g{100, 100, "test"};
	addGameObject(&g);

	while (win.isOpen())
	{
		sf::Event event;
		while (win.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				win.close();
		}

		update();

		render();
	}
}

void Game::update()
{
	// Implement game here
}

void Game::render()
{
	win.clear();

	for (GameObject* obj : gameObjects)
	{
		Sprite* s = obj->getSprite();
		win.draw(*s);
	}

	win.display();
}

void Game::addGameObject(GameObject* obj)
{
	gameObjects.push_back(obj);
}