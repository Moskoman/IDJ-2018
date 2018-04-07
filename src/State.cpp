#include "../include/State.h"

State::State() {
	
	quitRequested = false;
	LoadAssets();

};

State::~State() {
	
	objectArray.clear();
};


void State::Update(float dt) {
	
	Input();
	for (auto i = 0; i < objectArray.size(); i++) {
		if (objectArray[i]->IsDead()) {
			objectArray.erase(objectArray.begin() + i);
		}
	}

};

void State::Render() {

	for (int i = 0; i < objectArray.size(); i++) {
		objectArray[i]->Render();
		
	}
}


void State::LoadAssets() {

	GameObject *background = new GameObject();
	background->Box.x, background->Box.y = 0;
	Sprite *backgroundSprite = new Sprite(background, "img/ocean.jpg");
	background->AddComponent(backgroundSprite);
	objectArray.emplace_back(background);
	music.Open("audio/stageState.ogg");
	music.Play();
};

void State::Input() {
	SDL_Event event;
	int mouseX, mouseY;

	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event)) {

		// Se o evento for quit, setar a flag para terminação
		if (event.type == SDL_QUIT) {
			quitRequested = true;
		}

		// Se o evento for clique...
		if (event.type == SDL_MOUSEBUTTONDOWN) {

			// Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
			for (int i = (int)objectArray.size() - 1; i >= 0; i--) {
				// Obtem o ponteiro e casta pra Face.
				GameObject* go = (GameObject*)objectArray[i].get();
				// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
				// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
				// ao usar get(), violamos esse princípio e estamos menos seguros.
				// Esse código, assim como a classe Face, é provisório. Futuramente, para
				// chamar funções de GameObjects, use objectArray[i]->função() direto.
				//                std::cout << "box " << i << ":\n\tx: " << go->box.x << " y: " << go->box.y << "\n\tw: " << go->box.w << " h: " << go->box.h << std::endl;
				if (go->Box.Contains(mouseX, mouseY)) {
					Face* face = (Face*)go->GetComponent("Face");
					if (nullptr != face) {
						// Aplica dano
						face->Damage(std::rand() % 10 + 10);
						// Sai do loop (só queremos acertar um)
						break;
					}
				}
			}
		}
		if (event.type == SDL_KEYDOWN) {
			// Se a tecla for ESC, setar a flag de quit
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				quitRequested = true;
			}
			// Se não, crie um objeto
			else {
				Vec2 objPos = Vec2(200, 0).Rotate(-M_PI + M_PI * (rand() % 1001) / 500.0) + Vec2(mouseX, mouseY);
				AddObject(mouseX, mouseY);
			}
		}
	}
}

bool State::QuitRequested() { return quitRequested; };

void State::AddObject(int posX, int posY) {
	
	GameObject *GO = new GameObject();
	Sprite* pingu = new Sprite(GO, "../assets/img/penguinface.png");
	GO->Box.x = posX - (GO->Box.w / 2);
	GO->Box.y = posY - (GO->Box.h / 2);
	GO->AddComponent(pingu);

	Sound* pinguSoundEffect = new Sound(GO, "../assets/audio/boom.wav");
	GO->AddComponent(pinguSoundEffect);

	Face* pinguFace = new Face(GO);
	GO->AddComponent(pinguFace);

	objectArray.emplace_back(GO);



};