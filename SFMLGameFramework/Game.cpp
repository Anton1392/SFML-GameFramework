#include <iostream>
#include <vector>

#include "Game.h"
#include "AssetManager.h"
#include "GameObject.h"
#include "GameState.h"
#include "Tools.h"
#include "InputManager.h"

using namespace sf;
using namespace std;

Game::Game()
	:win{ sf::VideoMode(800, 600), "SFML Window" }
{
	win.setFramerateLimit(144);
}

void Game::run()
{
	// Initial setup
	AssetManager::load();
	InputManager::setWindow(&win);

	// Creates game states
	addGameState(new GameState("MAIN"));
	addGameState(new GameState("MENU"));
	setGameState("MAIN");

	GameObject g{100, 100, "anim"};
	g.setSize(256, 256);
	g.anim.setInterval(1.0/10);

	GameObject g2{100, 400, "anim2"};
	g2.setSize(108, 150);
	g2.anim.setInterval(0.1);

	currentState()->addGameObject(&g);
	currentState()->addGameObject(&g2);

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

			// If the mouse was pressed
			if (event.type == Event::MouseButtonPressed)
				currentState()->processMouseInput(event.mouseButton.button);

			// If a key was pressed
			if (event.type == Event::KeyPressed)
				currentState()->processKeyBoardInput(event.key.code);
		}

		// Measure frame time
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