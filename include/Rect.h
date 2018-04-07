#pragma once
#include "Vec2.h"

class Rect {

public:

	Rect();
	Rect(float x, float y, float w, float h);
	~Rect();

	float x, y, w, h;
	Vec2 Center();

	bool Contains(float posX, float posY);

};