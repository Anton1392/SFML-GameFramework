#include <string>
#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>

#include <filesystem>

#include "AssetManager.h"


using namespace std;
using namespace sf;
using namespace std::experimental::filesystem;


// Static dictionary of all textures.
map<string, Texture> AssetManager::textures;
map<string, Font> AssetManager::fonts;
map<string, SoundBuffer> AssetManager::sounds;
vector<Sound> AssetManager::activeSounds;

// Loads all assets, they are only stored in memory once.
void AssetManager::load()
{
	// Loads all textures, fonts, and sounds that are in their specific folders.
	string path = "../res/textures/";
	for (auto & p : directory_iterator(path))
	{
		// Convert the path to a string(stream)
		ostringstream oss;
		oss << p;

		// Load texture
		Texture t;
		t.loadFromFile(oss.str());

		// Store texture
		string name = p.path().filename().string();
		textures[name] = t;
		cout << "Texture " + name + " successfully loaded." << endl;
	}

	path = "../res/fonts/";
	for (auto & p : directory_iterator(path))
	{
		// Convert the path to a string(stream)
		ostringstream oss;
		oss << p;

		// Load font
		Font f;
		f.loadFromFile(oss.str());

		// Store font
		string name = p.path().filename().string();
		fonts[name] = f;
		cout << "Font " + name + " successfully loaded." << endl;
	}

	path = "../res/sounds/";
	for (auto & p : directory_iterator(path))
	{
		// Convert the path to a string(stream)
		ostringstream oss;
		oss << p;

		// Load sound
		SoundBuffer s;
		s.loadFromFile(oss.str());

		// Store sound
		string name = p.path().filename().string();
		sounds[name] = s;

		cout << "Sound " + name + " successfully loaded." << endl;
	}

	// Sets up the sound vector with quiet sounds.
	for (int i = 0; i < soundChannelCount; i++)
	{
		Sound s;
		activeSounds.push_back(s);
	}
}

// Returns a texture by name.
Texture* AssetManager::getTexture(string name)
{
	return &textures[name];
}

// Returns a font by name.
Font* AssetManager::getFont(string name)
{
	return &fonts[name];
}

// Plays a sound
void AssetManager::playSound(string name)
{
	// Finds a non-playing sound, and plays the soundbuffer in that slot.
	//for (Sound s : activeSounds)
	for(int i = 0; i < activeSounds.size(); i++)
	{
		if (activeSounds[i].getStatus() != SoundSource::Status::Playing)
		{
			activeSounds[i].setBuffer(sounds[name]);
			activeSounds[i].play();
			break;
		}
	}
}