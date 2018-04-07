#pragma once
#include <iostream>
#include <vector>
#include "Rect.h"
using std::vector;
using std::string;
#include "Component.h"
#include <algorithm>

class GameObject {

public:

	GameObject();
	~GameObject();
	
	void Update(float dt);
	void Render();
	bool IsDead();
	void RequestDelete();
	void AddComponent(Component *cpt);
	void RemoveComponent(Component *cpt);
	Component* GetComponent(string type);

	Rect Box;

private:

	vector <Component*> components;
	bool isDead;
	


};