#pragma once
#include "GameObject.h"

class GameState
{
public:
	GameState(std::string _name);
	void addGameObject(GameObject* obj);
	void update();
	void render(sf::RenderWindow* win);

	std::string name;

private:
	std::vector<GameObject*> gameObjects;
};