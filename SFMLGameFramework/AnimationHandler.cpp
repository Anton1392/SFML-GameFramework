#include <SFML/Graphics.hpp>
#include <iostream>

#include "AnimationHandler.h"
#include "AssetManager.h"

using namespace sf;
using namespace std;

AnimationHandler::AnimationHandler(string _textureName)
	:t{0.2}
{
	textureName = _textureName;
}

void AnimationHandler::tick(float deltaTime)
{
	if (t.tick(deltaTime))
	{
		// Resets the texture, and the texture rect.
		sprite->setTexture(*AssetManager::getTexture(textureName), true);

		// Keeps track of frames.
		frame += 1;
		if (frame > totalFrames)
			frame = 1;
		
		// Gets the size of the sprite.
		FloatRect rec = sprite->getLocalBounds();

		// Finds left side of spritesheet
		int left = (frame - 1) * rec.width/totalFrames;

		// Applies the texture properly.
		sprite->setTextureRect(IntRect(left, 0, rec.width/totalFrames, rec.height));
	}
}

void AnimationHandler::setAnimation(Sprite* _sprite, int _totalFrames)
{
	sprite = _sprite;
	totalFrames = _totalFrames;

	// First frame
	FloatRect rec = sprite->getLocalBounds();
	sprite->setTextureRect(IntRect(0, 0, rec.width/totalFrames, rec.height));
}

void AnimationHandler::setInterval(float seconds)
{
	t.setInterval(seconds);
}