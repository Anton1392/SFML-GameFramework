#pragma once

#include <SFML/Graphics.hpp>

class AssetManager
{
	public:
		static void Load();
		static sf::Texture* getTexture(std::string name);

	private:
		static std::map<std::string, sf::Texture> textures;
};