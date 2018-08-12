#pragma once
#include "GameObject.h"

// Handles a particular game state, e.g main game, menu, pause, etc.
class GameState
{
	public:
		GameState(std::string _name);
		void addGameObject(GameObject* obj);
		void update(float deltaTime);
		void render(sf::RenderWindow* win);

		std::string name;

	private:
		std::vector<GameObject*> gameObjects;
};