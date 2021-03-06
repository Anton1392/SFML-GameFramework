#pragma once

#include <string>

#include "GameObject.h"

// Basic button. Accepts a void function which is called when the button is clicked.
class Button : public GameObject
{
	public:
		Button(int x, int y, int w, int h,std::string txt, void(*f)());
		void click();
		sf::Text* getText();

	private:
		sf::Text text;
		void (*func)(); 
};

class TextBox : public GameObject
{
	public:
		TextBox(int x, int y, int w, int h,std::string txt);
		sf::Text* getText();

	private:
		sf::Text text;
};

// Holding class of UI elements, so far just buttons.
class UI
{
	public:
		void render(sf::RenderWindow* win);
		void addButton(int x, int y, int w, int h, std::string txt, void(*f)());
		void addTextBox(int x, int y, int w, int h, std::string txt);
		void processMouseInput(sf::Mouse::Button b);

	private:
		std::vector<Button*> btns;
		std::vector<TextBox*> txtBoxes;
};

