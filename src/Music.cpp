#include "../include/Music.h"

Music::Music() {
	music = nullptr;
};

Music::Music(string filePath) {
	Music();
	Open(filePath);
};

Music::~Music() {
	Stop();
	Mix_FreeMusic(music);
};

void Music::Play(int times) {
	if (times < 0) {
		times = -1;
	}
	if (music != nullptr) {
		Mix_PlayMusic(music, times);
	}
	else
		cout << "No music loaded " << SDL_GetError() << endl;
};

void Music::Stop(int msToStop) {
	Mix_FadeOutMusic(msToStop);
};

void Music::Open(string filePath) {

	music = Mix_LoadMUS(filePath.c_str());

	if (music == nullptr) {
		cout << "Error loading music " << SDL_GetError() << endl;
	
	}
};

bool Music::IsOpen() {
	if (music != nullptr) {
		return true;
	}
	return false;
};