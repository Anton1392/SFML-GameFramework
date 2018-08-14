#include <string>
#include <iostream>

#include "UI.h"
#include "AssetManager.h"
#include "InputManager.h"

using namespace std;
using namespace sf;

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

TextBox::TextBox(int x, int y, int w, int h, string txt)
	:GameObject(x, y, "textbox")
{
	// Set textbox visuals
	anim.disable();
	setSize(w, h);

	// Text visuals
	text.setString(txt);
	text.setFont(*AssetManager::getFont("test"));
	text.setFillColor(sf::Color::White);

	// Text centering
	auto txtRect = text.getGlobalBounds();
	auto boxPos = getPosition();
	auto boxSize = getSize();
	int new_x = boxPos.x - text.getLocalBounds().left + boxSize.x/2 - txtRect.width/2;
	int new_y = boxPos.y - text.getLocalBounds().top + boxSize.y/2 - txtRect.height/2;
	text.setPosition(new_x, new_y);
}

Text* TextBox::getText()
{
	return &text;
}

// Draws all UI elements on the specific window.
void UI::render(sf::RenderWindow* win)
{
	for (Button* b : btns)
	{
		win->draw(*b->getSprite());
		win->draw(*b->getText());
	}
	for (TextBox* b : txtBoxes)
	{
		win->draw(*b->getSprite());
		win->draw(*b->getText());
	}
}

void UI::addButton(int x, int y, int w, int h, std::string txt, void(*f)())
{
	btns.push_back(new Button(x, y, w, h, txt, f));
}

void UI::addTextBox(int x, int y, int w, int h, std::string txt)
{
	txtBoxes.push_back(new TextBox(x, y, w, h, txt));
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
