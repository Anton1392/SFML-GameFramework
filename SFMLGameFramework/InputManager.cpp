#include <iostream>

#include "InputManager.h"
#include "GameObject.h"
using namespace sf;
using namespace std;

RenderWindow* InputManager::win;

// Sets the proper window. This is used for mouse coordinates.
void InputManager::setWindow(RenderWindow* w)
{
	win = w;
}

// Whether an object (it's sprite) has been clicked.
bool InputManager::isObjectClicked(GameObject* g, Mouse::Button b)
{
	return isSpriteClicked(g->getSprite(), b);
}

// Whether a sprite has been clicked.
bool InputManager::isSpriteClicked(Sprite* s, Mouse::Button b)
{
	if (Mouse::isButtonPressed(b))
	{
		FloatRect r = s->getGlobalBounds();
		Vector2i pos = Mouse::getPosition(*win);
		if (r.contains(pos.x, pos.y))
		{
			return true;
		}
	}
	
	return false;
}