#include "../include/Sound.h"

Sound::Sound(GameObject * associated) : Component(associated){
	this->associated = associated;
	chunk = nullptr;
}

Sound::Sound(GameObject *associated, string file) : Sound(associated) {
	Open(file);
	
};

Sound::~Sound() {
	
	if (chunk != nullptr) {
		Stop();
		Mix_FreeChunk(chunk);
	}
};

void Sound::Play(int times){

	channel = Mix_PlayChannel(-1, chunk, times);
}

void Sound::Stop()
{
	if (chunk != nullptr) {
		Mix_HaltChannel(channel);
	}
}

void Sound::Open(string file)
{
	chunk = Mix_LoadWAV(file.data());
	if (chunk == nullptr) {
		std::cout << "Error loading sound!";
	};
}

bool Sound::IsOpen()
{
	if (chunk != nullptr) {
		return true;
	}
	return false;
}

void Sound::Update(){};

void Sound::Render()
{
}

bool Sound::Is(string type)
{
	if (type == "Sound") {
		return true;
	}

	return false;
}
