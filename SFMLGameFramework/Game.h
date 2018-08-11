#pragma once
#include "GameObject.h"

class Game
{
	public:
		Game();
		void run();
		void addGameObject(GameObject* obj);

	private:
		void update();
		void render();

		std::vector<GameObject*> gameObjects;

		sf::RenderWindow win;
};