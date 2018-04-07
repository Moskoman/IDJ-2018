#pragma once
#include <iostream>

class GameObject;

class Component {

public:

	Component(GameObject *associated);

	virtual ~Component();

	void virtual Update() = 0;

	void virtual Render() = 0;

	bool virtual Is(std::string type) = 0;

protected:

	GameObject * associated;
};