#include "../include/Component.h"

Component::Component(GameObject *associated) {
	this->associated = associated;
};

Component::~Component() {};