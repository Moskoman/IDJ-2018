#include "../include/Vec2.h"

Vec2::Vec2() {};

Vec2::Vec2(float x, float y) { x = x; y = y; };

Vec2 Vec2::operator+ (const Vec2& sumVector) const {

	Vec2 result;
	result.x = (x + sumVector.x);
	result.y = (y + sumVector.y);

	return result;
}

Vec2 Vec2::operator- (const Vec2& minusVector) const {

	Vec2 result;
	result.x = (x - minusVector.x);
	result.y = (y - minusVector.y);

	return result;
}

Vec2 Vec2::operator* (const float& scalar) const {
	
	return Vec2(x * scalar, y * scalar);
}

float Vec2::magnitude() {
	
	return sqrt(pow(x, 2) + pow(y, 2));
};

Vec2 Vec2::normalized() {

	return Vec2 ((x/fabs(magnitude())), y/fabs(magnitude()));
}

Vec2 Vec2::Rotate(float angle) {
	return Vec2(x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle));
}