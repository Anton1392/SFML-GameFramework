#include <iostream>
#include <vector>

#include "Game.h"
#include "AssetManager.h"
#include "GameObject.h"
#include "GameState.h"
#include "Tools.h"
#include "InputManager.h"
#include "UI.h"

using namespace sf;
using namespace std;

Game::Game()
	:win{ sf::VideoMode(1280, 1024), "SFML Window" }
{
	win.setFramerateLimit(144);
}

void btnTest()
{
	cout << "HELLO MR BUTTON ME PLAY SOUND NOW" << endl;
	AssetManager::playSound("test.wav");
}

void Game::run()
{
	// Initial setup
	AssetManager::load();
	InputManager::setWindow(&win);

	// Creates game states
	addGameState(new GameState("MAIN"));
	setGameState("MAIN");

	GameObject g{100, 100, "anim.png"};
	g.anim.setAnimation(g.getSprite(), 6);
	g.setSize(256, 256);
	g.anim.setInterval(1.0/10);
	currentState()->addGameObject(&g);

	currentState()->ui.addButton(0,0,200,50,"hi", btnTest );
	currentState()->ui.addTextBox(400, 400, 200, 100, "ur mom gey");
	currentState()->ui.addTextBox(400, 520, 200, 100, "no u");

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