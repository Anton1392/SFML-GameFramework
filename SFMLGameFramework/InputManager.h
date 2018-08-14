#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class InputManager
{
	public:
		static void setWindow(sf::RenderWindow* w);
		static bool isSpriteClicked(sf::Sprite* s, sf::Mouse::Button b);
		static bool isObjectClicked(GameObject* g, sf::Mouse::Button b);

	private: 
		// The window to check clicks within.
		static sf::RenderWindow* win;
};
