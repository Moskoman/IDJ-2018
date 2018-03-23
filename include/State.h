#pragma once
#define INCLUDE_SDL 
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"
#include "Sprite.h"
#include "Music.h"

class State {

public:

	State();
	~State();

	bool QuitRequested();
	
	void LoadAssets();

	void Update(float dt);

	void Render();

private:

	Sprite bg;

	Music music;

	bool quitRequested;
};