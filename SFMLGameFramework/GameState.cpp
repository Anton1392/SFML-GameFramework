#include "GameState.h"

using namespace sf;
using namespace std;

GameState::GameState(string _name)
	:name{_name}
{}

// Adds a game object to this state.
void GameState::addGameObject(GameObject* obj)
{
	gameObjects.push_back(obj);
}

// Draws all game objects onto the provided window.
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

// Main game loop.
void GameState::update(float deltaTime)
{
	// Implement game here
	for (GameObject* o : gameObjects)
	{
		o->update(deltaTime);
	}
}