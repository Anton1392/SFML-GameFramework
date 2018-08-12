#include "GameState.h"

using namespace sf;
using namespace std;

GameState::GameState(string _name)
	:name{_name}
{}

void GameState::addGameObject(GameObject* obj)
{
	gameObjects.push_back(obj);
}

void GameState::render(RenderWindow* win)
{
	win->clear();

	for (GameObject* obj : gameObjects)
	{
		Sprite* s = obj->getSprite();
		win->draw(*s);
	}

	win->display();
}

void GameState::update()
{
	// Implement game here
}