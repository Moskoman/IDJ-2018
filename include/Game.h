#ifndef GAME_H
#define GAME_H
#define INCLUDE_SDL 
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"
#include <string>
#include <iostream>
#include "Music.h"
#include "State.h"

using namespace std;

class Game {

public:

	~Game();

	void Run();

	SDL_Renderer* GetRenderer();

	State& GetState();

	static Game* GetInstance();

private:

	Game(string Title, int WIDTH, int HEIGHT);
	
	static Game* instance;

	SDL_Window* window;

	SDL_Renderer* renderer;

	State* state;

};

#endif