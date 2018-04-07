#include "../include/Face.h"

Face::Face(GameObject * associated) : Component(associated){
	this->hitPoints = 30;
}

Face::~Face() {};

void Face::Damage(int damage) {

	this -> hitPoints -= damage;
	if (this->hitPoints <= 0) {
		this->associated->RequestDelete();
		Component* associatedSound = this->associated->GetComponent("Sound");
		if (associatedSound != nullptr) {
			Sound* s = (Sound*)associatedSound;
			s->Play();
		}
	}
}

void Face::Update(){};

void Face::Render() {};

bool Face::Is(string type)
{
	if (type == "Face") {
		return true;
	}

	return false;
}
