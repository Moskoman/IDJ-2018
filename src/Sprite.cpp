#include "../include/Sprite.h"
#include "../include/Game.h"


Sprite::Sprite(GameObject *associated) : Component(associated) {
	texture = nullptr;
};

Sprite::Sprite(GameObject *associated, string filePath) : Component (associated) {
	texture = nullptr;
	Sprite::Open(filePath);
};

Sprite::~Sprite() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
	}
};

void Sprite::Open(string filePath) {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
	}
	texture = IMG_LoadTexture(Game::GetInstance()->GetRenderer(), filePath.c_str());
	
	if (texture == nullptr) {
		cout << "Error loading texture. " << SDL_GetError() << endl;
		//exit(-1);
	}
	SDL_QueryTexture(texture, NULL, NULL, &width, &height);

	//Temporary Values
	SetClip(0, 0, width, height);

};

void Sprite::SetClip(int x, int y, int w, int h) {

	clipRect.x = x;
	clipRect.y = y;
	clipRect.h = h;
	clipRect.w = w;

	associated->Box.w = w;
	associated->Box.h = h;
};

void Sprite::Render() {
	SDL_Rect dstRect;
	dstRect.x = associated->Box.x;
	dstRect.y = associated->Box.y;
	dstRect.w = clipRect.w;
	dstRect.h = clipRect.h;

	SDL_RenderCopy(Game::GetInstance()->GetRenderer(), texture, &clipRect, &dstRect);

};

int Sprite::GetHeight() {
	return height;
};

int Sprite::GetWidth() {
	return width;
};

bool Sprite::IsOpen() {
	if (texture != nullptr) {
		return true;
	}
	return false;
};

void Sprite::Update() {};

bool Sprite::Is(string type) {

	if (type == "Sprite") {
		return true;
	}
	
	return false;
};