#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// Handles all assets and their loading. 
class AssetManager
{
	public:
		static void load();
		static sf::Texture* getTexture(std::string name);
		static void playSound(std::string name);
		static const int soundChannelCount = 50;

	private:
		static std::map<std::string, sf::Texture> textures;

		static std::map<std::string, sf::SoundBuffer> sounds;
		static std::vector<sf::Sound> activeSounds;
};