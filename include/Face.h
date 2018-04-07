#include "Component.h"
#include "GameObject.h"
#include "Sound.h"
#include <iostream>
using std::string;

class Face : public Component {

public:

	Face(GameObject *associated);
	~Face();
	void Damage(int damage);
	void Update();
	void Render();
	bool Is(string type);

private:

	int hitPoints;
};