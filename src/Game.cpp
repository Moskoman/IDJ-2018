#include "../include/Game.h"

Game* Game::instance = nullptr;


Game::Game(string Title, int WIDTH, int HEIGHT) {

	//Singleton
	if (instance != nullptr) {
		cout << "Multiple Game Instances " << SDL_GetError() << endl;
		SDL_Quit();
	}
	else
		instance = this;

	//SDL Modules Initialization
	SDL_Init(SDL_INIT_AUDIO | SDL_INIT_TIMER | SDL_INIT_VIDEO);
	IMG_INIT_PNG;
	IMG_INIT_JPG;
	Mix_Init(MIX_INIT_OGG);
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	Mix_AllocateChannels(32);

	//Window creation
	window = SDL_CreateWindow(Title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	instance = this;

	state = new State();
};

Game::~Game() {
		
	Mix_CloseAudio();
	Mix_Quit();
	IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	};

SDL_Renderer* Game::GetRenderer() {
	
	if (renderer != nullptr) {
		return renderer;
	}

	return nullptr;
};

State& Game::GetState() {
	if (state != nullptr) {
		return *state;
	}
	cout << "Error loading state on Game " << SDL_GetError() << endl;
	exit(-1);
	return *state;
};

Game* Game::GetInstance() {

	if (instance == nullptr) {
		instance = new Game("Let's Get Those Aliens!", 800, 600);
	}
		

	return instance;
};

void Game::Run() {
	state->Update(0.1);
	state->Render();
	SDL_RenderPresent(GetRenderer());
	SDL_Delay(33);
};