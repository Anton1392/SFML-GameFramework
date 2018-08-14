#pragma once
#include "GameObject.h"
#include "UI.h"

// Handles a particular game state, e.g main game, menu, pause, etc.
class GameState
{
	public:
		GameState(std::string _name);
		void addGameObject(GameObject* obj);
		void update(float deltaTime);
		void render(sf::RenderWindow* win);
		void processMouseInput(sf::Mouse::Button b);
		void processKeyBoardInput(sf::Keyboard::Key k);

		std::string name;

		UI ui;

	private:
		std::vector<GameObject*> gameObjects;
};