#include "AssetManager.h"

#include <string>
#include <map>
#include <iostream>

using namespace std;
using namespace sf;

map<string, Texture> AssetManager::textures;

void AssetManager::Load()
{
	string textureNames[] = {"test"};

	for (string s : textureNames)
	{
		Texture t;
		t.loadFromFile("../res/textures/" + s + ".png");
		textures[s] = t;
		cout << "Texture " + s + " successfully loaded." << endl;
	}
}

Texture* AssetManager::getTexture(string name)
{
	return &textures[name];
}