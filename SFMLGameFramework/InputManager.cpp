#include <iostream>

#include "InputManager.h"
#include "GameObject.h"
using namespace sf;
using namespace std;

RenderWindow* InputManager::win;

void InputManager::setWindow(RenderWindow* w)
{
	win = w;
}

bool InputManager::isObjectClicked(GameObject* g, Mouse::Button b)
{
	return isSpriteClicked(g->getSprite(), b);
}

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