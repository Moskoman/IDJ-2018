#pragma once
#include "Vector2.h"

class Rect {

public:

	Rect();
	Rect(float x, float y, float w, float h);
	~Rect();

	float x, y, w, h;
	Vector2 Center();

};