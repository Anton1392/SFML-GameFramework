#include <iostream>

#include "GameState.h"
#include "InputManager.h"

using namespace sf;
using namespace std;

GameState::GameState(string _name)
	:name{_name}, ui{}
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

	ui.render(win);

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

void GameState::processMouseInput(Mouse::Button b)
{
	// IMPLEMENT NEEDED CLICK LOGIC HERE
	for (GameObject* g : gameObjects)
	{
		if (InputManager::isObjectClicked(g, b))
		{

			cout << "An object was clicked with button " << b << "." << endl;
		}
	}

	// The UI may have been pressed.
	ui.processMouseInput(b);
}

void GameState::processKeyBoardInput(Keyboard::Key k)
{
	// IMPLEMENT NEEDED KEY LOGIC HERE
	cout << "Key " << k << " was pressed" << endl;
	if (k == Keyboard::Escape)
	{
		cout << "It was escape." << endl;
	}
}