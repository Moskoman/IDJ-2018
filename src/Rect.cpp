#include "../include/Rect.h"
#include "../include/Vec2.h"

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

Vec2 Rect::Center() {

	float centerX = x + (w / 2);
	float centerY = y + (h / 2);
	Vec2 vec2(centerX, centerY);

	return vec2;
};

bool Rect::Contains(float posX, float posY) {
	if (posX < x || posX > x + w) return false;
	if (posY < y || posY > y + h) return false;
	return true;
}

