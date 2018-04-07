#ifndef SPRITE_H
#define SPRITE_H
#define INCLUDE_SDL 
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"
#include <iostream>
#include <memory>
#include <string>
#include "Component.h"
using namespace std;

class Sprite : public Component {

public:

	Sprite(GameObject *associated);
	Sprite(GameObject *associated, string filePath);
	~Sprite();
	void Open(string filePath);
	void SetClip(int x, int y, int w, int h);
	void Render();
	int GetWidth();
	int GetHeight();
	bool IsOpen();
	void Update();
	bool Is(string type);

private:

	SDL_Texture *texture;
	int width;
	int height;
	SDL_Rect clipRect;

};

#endif SPRITE_H