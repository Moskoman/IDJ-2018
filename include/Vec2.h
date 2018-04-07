#pragma once
#include <math.h>

class Vec2 {

public:

	float x, y;

	Vec2();
	Vec2(float x, float y);

	Vec2 operator+ (const Vec2& sumVector) const;
	Vec2 operator- (const Vec2& minusVector) const;
	Vec2 operator* (const float& scalar) const;

	float magnitude();

	Vec2 normalized();

	Vec2 Rotate(float angle);
	
};