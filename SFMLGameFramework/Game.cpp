#include <iostream>
#include <vector>

#include "Game.h"
#include "AssetManager.h"
#include "GameObject.h"
#include "GameState.h"

using namespace sf;
using namespace std;

Game::Game()
	:win{ sf::VideoMode(800, 600), "SFML Window" }
{
	win.setFramerateLimit(144);
}

void Game::run()
{
	AssetManager::load();

	// Creates game states
	addGameState(new GameState("MAIN"));
	addGameState(new GameState("MENU"));
	setGameState("MAIN");

	GameObject g{100, 100, "test"};

	currentState()->addGameObject(&g);

	// Measures frame time
	sf::Clock clock;
	while (win.isOpen())
	{
		sf::Event event;
		while (win.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				win.close();
		}

		// Mesaure frame time
		float deltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();

		// Update and render current state.
		currentState()->update(deltaTime);
		currentState()->render(&win);
	}
}

void Game::addGameState(GameState* state)
{
	gameStates.push_back(state);
}

// Sets which gamestate to use.
void Game::setGameState(string stateName)
{
	for (int i = 0; i < gameStates.size(); i++)
	{
		if (gameStates[i]->name == stateName)
		{
			currentGameStateIdx = i;
			break;
		}
	}
}

// Returns current state.
GameState* Game::currentState()
{
	return gameStates[currentGameStateIdx];
}

// Returns a particular gamestate by name.
GameState* Game::getGameState(string stateName)
{
	for (GameState* g : gameStates)
	{
		if (g->name == stateName)
		{
			return g;
		}
	}
}