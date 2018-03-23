#include "../include/Sprite.h"
#include "../include/Game.h"


Sprite::Sprite() {
	texture = nullptr;
};

Sprite::Sprite(string filePath) {
	texture = nullptr;
	Open(filePath);
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
	clipRect.w = w;
	clipRect.h = h;
};

void Sprite::Render(int x, int y) {
	SDL_Rect dstRect;
	dstRect.x = x;
	dstRect.y = y;
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