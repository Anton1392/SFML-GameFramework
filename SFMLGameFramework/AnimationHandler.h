#pragma once

#include <SFML/Graphics.hpp>

#include "Tools.h"

class AnimationHandler
{
	public:
		AnimationHandler(std::string _textureName);
		void tick(float deltaTime);
		void setAnimation(sf::Sprite* sprite, int totalFrames);
		void setInterval(float seconds);
		void disable();
		void enable();

	private:
		bool enabled = true;
		sf::Sprite* sprite;
		Timer t;
		int totalFrames;
		int frame = 1;
		std::string textureName; // Keeps track of original texture.
};