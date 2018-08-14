#include "AssetManager.h"
#include "GameObject.h"

using namespace sf;
using namespace std;

GameObject::GameObject(int x, int y, string textureName)
	:anim{textureName}
{
	// Initializes texture and position.
	Texture* t{ AssetManager::getTexture(textureName) };
	sprite.setTexture(*t);
	setPosition(x, y);

	anim.setAnimation(&sprite, 1);
}

void GameObject::setPosition(int x, int y)
{
	sprite.setPosition(x, y);
}

Vector2f GameObject::getPosition()
{
	return sprite.getPosition();
}

Vector2f GameObject::getSize()
{
	FloatRect rect = sprite.getGlobalBounds();
	return Vector2f{ rect.width, rect.height };
}

void GameObject::setSize(float w, float h)
{
	// Resets the scale, then rescales it to fit the new dimensions.
	sprite.setScale(1, 1);
	FloatRect rect = sprite.getGlobalBounds();
	float oldW{ rect.width };
	float oldH{ rect.height };
	sprite.setScale(w / oldW, h / oldH);
}

Sprite* GameObject::getSprite()
{
	return &sprite;
}

void GameObject::update(float deltaTime)
{
	anim.tick(deltaTime);
}