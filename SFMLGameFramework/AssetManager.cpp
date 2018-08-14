#include <string>
#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "AssetManager.h"

using namespace std;
using namespace sf;

// Static dictionary of all textures.
map<string, Texture> AssetManager::textures;
map<string, Font> AssetManager::fonts;
map<string, SoundBuffer> AssetManager::sounds;
vector<Sound> AssetManager::activeSounds;

// Loads all assets, they are only stored in memory once.
void AssetManager::load()
{
	// Expand this array to add more textures for loading.
	string textureNames[] = {"test", "anim", "anim2", "button", "textbox"};
	string soundNames[] = {"test"};
	string fontNames[] = {"test"};

	// Loads and stores all textures.
	for (string s : textureNames)
	{
		Texture t;
		t.loadFromFile("../res/textures/" + s + ".png");
		textures[s] = t;
		cout << "Texture " + s + " successfully loaded." << endl;
	}

	// Loads and stores all fonts
	for (string s : fontNames)
	{
		Font f;
		f.loadFromFile("../res/fonts/" + s + ".ttf");
		fonts[s] = f;
		cout << "Font " + s + " successfully loaded." << endl;
	}

	// Loads and stores all sounds
	for (string s : soundNames)
	{
		SoundBuffer bf;
		bf.loadFromFile("../res/sounds/" + s + ".wav");
		sounds[s] = bf;
		cout << "Sound " + s + " successfully loaded." << endl;
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
			cout << "Tried playing sound " + name + "." << endl;
			break;
		}
	}
}