#pragma once
#define INCLUDE_SDL 
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"
#include "Sprite.h"
#include "Music.h"
#include <memory>
#include <vector>
#include "Face.h"
#include "GameObject.h"
using std::vector;

class State {

public:

	State();
	~State();

	bool QuitRequested();
	
	void LoadAssets();

	void Update(float dt);

	void Render();

	void Input();

	void AddObject(int posX, int posY);
	

private:

	vector <unique_ptr <GameObject>> objectArray;

	Music music;

	bool quitRequested;
};