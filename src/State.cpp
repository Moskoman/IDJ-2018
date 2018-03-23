#include "../include/State.h"

State::State() {
	
	quitRequested = false;
	LoadAssets();

};

void State::Update(float dt) {
	
	if (SDL_QuitRequested() == true) {
		quitRequested = true;
	}
};

void State::Render() {

	bg.Render(0, 0);
};

void State::LoadAssets() {

	bg.Open("assets/img/ocean.jpg");
	music.Open("assets/audio/stageState.ogg");
	music.Play();
};


