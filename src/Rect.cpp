#include "../include/Rect.h"
#include "../include/Vector2.h"

Rect::Rect() {
	x = 0;
	y = 0;
	w = 0;
	h = 0;
};

Rect::Rect(float x, float y, float w, float h) {

	x = x;
	y = y;
	w = w;
	h = h;
};

Rect::~Rect() {};

Vector2 Rect::Center() {

	float centerX = x + (w / 2);
	float centerY = y + (h / 2);
	Vector2 vec2(centerX, centerY);

	return vec2;
};



