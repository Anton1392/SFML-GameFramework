#pragma once

#include "GameState.h"

// Handles the game in general.
class Game
{
	public:
		Game();
		void run();
		void addGameState(GameState* state);
		void setGameState(std::string stateName);
		GameState* currentState();
		GameState* getGameState(std::string stateName);

	private:
		int currentGameStateIdx;
		sf::RenderWindow win;
		std::vector<GameState*> gameStates;
};