#pragma once
#define INCLUDE_SDL 
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"
#include <string>
#include <iostream>
using namespace std;

class Music {

public:

	Music();
	Music(string filePath);
	~Music();
	void Play(int times = -1);
	void Stop(int msToStop = 1500);
	void Open(string filePath);
	bool IsOpen();

private:

	Mix_Music *music;

};