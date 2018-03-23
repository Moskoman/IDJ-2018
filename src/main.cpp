#define INCLUDE_SDL 
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE
#include "../include/SDL_include.h"
#include <cstdlib>
#include <iostream>
#include "../include/Game.h"

int main(int argc, char** argv) {
	Game* myGame = Game::GetInstance();

	while (true) {
		SDL_Event windowEvent;

		//Check User Quit
		while (SDL_PollEvent(&windowEvent)) {
			if (windowEvent.type == SDL_QUIT) {
				exit(0);
				break;
			}
			myGame->Run();
		}
	}

	return 0;
}
