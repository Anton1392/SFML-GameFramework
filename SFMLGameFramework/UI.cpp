#include <string>
#include <iostream>

#include "UI.h"
#include "AssetManager.h"
#include "InputManager.h"

using namespace std;
using namespace sf;

// Draws all UI elements on the specific window.
void UI::render(sf::RenderWindow* win)
{
	for (Button* b : btns)
	{
		win->draw(*b->getSprite());
		win->draw(*b->getText());
	}
}

void UI::addButton(Button* b)
{
	btns.push_back(b);
}

// Checks if any buttons have been pressed.
void UI::processMouseInput(Mouse::Button b)
{
	for (Button* btn : btns)
	{
		if (InputManager::isObjectClicked(btn, b))
		{
			btn->click();
		}
	}
}

Button::Button(int x, int y, int w, int h, string txt, void(*f)())
	:GameObject(x, y, "button")
{
	// Set button visuals
	anim.disable();
	setSize(w, h);

	// Set on-click function
	func = f;

	// Text visuals
	text.setString(txt);
	text.setFont(*AssetManager::getFont("test"));
	text.setFillColor(sf::Color::White);

	// Text centering
	auto txtRect = text.getGlobalBounds();
	auto btnPos = getPosition();
	auto btnSize = getSize();
	int new_x = btnPos.x - text.getLocalBounds().left + btnSize.x/2 - txtRect.width/2;
	int new_y = btnPos.y - text.getLocalBounds().top + btnSize.y/2 - txtRect.height/2;
	text.setPosition(new_x, new_y);
}

void Button::click()
{
	func();
}

sf::Text* Button::getText()
{
	return &text;
}