#pragma once

#include <SFML/Graphics.hpp>

// Base game object, controls location + size of object, and its sprite.
class GameObject
{
	public:
		GameObject(int x, int y, std::string textureName);

		sf::Vector2f getPosition();
		void setPosition(int x, int y);

		sf::Vector2f getSize();
		void setSize(float w, float h);

		sf::Sprite* getSprite();

	private: 
		sf::Sprite sprite;
};
