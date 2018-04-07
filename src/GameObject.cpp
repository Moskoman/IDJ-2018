#include "../include/GameObject.h"

GameObject::GameObject() {
	isDead = false;
};

GameObject::~GameObject() {
	
	for (int i = 0; i != components.size();) {
		components.erase(components.begin() + components.size());

	}
};

void GameObject::Update(float dt) {

	for (auto i = 0; i < components.size(); i++) {
		components[i]->Update();
	};
};

void GameObject::Render() {
	for (auto i = 0; i < components.size(); i++) {
		components[i]->Render();
		
	};
}

bool GameObject::IsDead() { return isDead; };

void GameObject::RequestDelete() { isDead = true; };

void GameObject::AddComponent(Component *cpt) {
	
	components.push_back(cpt);


};

void GameObject::RemoveComponent(Component *cpt) {
	
	components.erase(std::remove(components.begin(), components.end(), cpt), components.end());

};

Component* GameObject::GetComponent(string type) {
	
	for (auto i = 0; i < components.size(); i++) {
		if (components[i]->Is(type)) {
			return components[i];
			break;
		}
		else {
			return nullptr;
		}

	};
};

