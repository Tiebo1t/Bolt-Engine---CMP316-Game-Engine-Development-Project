#include "World2.h"

Bolt::World2::World2()
{
}

Bolt::World2::~World2()
{
}

void Bolt::World2::Load()
{
	character = CreateNewGameObject();
	character->AddComponent<SpriteComp>();

	character2 = CreateNewGameObject();
	character2->AddComponent<SpriteComp>();

	// Initialising height positions and sizes for sprites
	posx[0] = 50;
	posy[0] = 50;
	heightx[0] = 50;
	heighty[0] = 50;

	posx[1] = 1000;
	posy[1] = 500;
	heightx[1] = 300;
	heighty[1] = 300;
}

void Bolt::World2::Start(SDL_Renderer*& renderer)
{
	int i = 0;
	for (auto& GO : gameObjects) {
		SpriteComp* sprite = GO->GetComponent<SpriteComp>();
		if (sprite != nullptr) {
			sprite->Start(renderer, posx[i], posy[i], heightx[i], heighty[i]);

			if (i == gameObjects.size()) i = 0;
			i++;
		}
	}
}

void Bolt::World2::Render(SDL_Renderer*& renderer)
{
	// Render all game objects with sprite components
	for (auto& GO : gameObjects) {
		SpriteComp* sprite = GO->GetComponent<SpriteComp>();
		if (sprite != nullptr) {
			sprite->Render(renderer);
		}
	}
}

void Bolt::World2::Update()
{
	// Update all game objects
	for (auto& GO : gameObjects) {
		GO->Update();
	}
}

void Bolt::World2::AddGameObject(GameObject* gameObject)
{
	gameObjects.push_back(gameObject);
}

Bolt::GameObject* Bolt::World2::CreateNewGameObject()
{
	GameObject* gameObject = new GameObject();
	AddGameObject(gameObject);
	return gameObject;
}
