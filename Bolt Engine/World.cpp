#include "World.h"

Bolt::World::World()
{
}

Bolt::World::~World()
{
}

void Bolt::World::Load()
{
	character = CreateNewGameObject();
	character->AddComponent<SpriteComp>();

	character2 = CreateNewGameObject();
	character2->AddComponent<SpriteComp>();

	// Initialising height positions and sizes for sprites
	posx[0] = 1280 / 2;
	posy[0] = 720 / 2;
	heightx[0] = 50;
	heighty[0] = 50;

	posx[1] = 500 / 2;
	posy[1] = 500 / 2;
	heightx[1] = 50;
	heighty[1] = 50;
}

void Bolt::World::Start(SDL_Renderer*& renderer)
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

void Bolt::World::Render(SDL_Renderer*& renderer)
{
	// Render all game objects with sprite components
	for (auto& GO : gameObjects) {
		SpriteComp* sprite = GO->GetComponent<SpriteComp>();
		if (sprite != nullptr) {
			sprite->Render(renderer);
		}
	}
}

void Bolt::World::Update()
{
	// Update all game objects
	for (auto& GO : gameObjects) {
		GO->Update();
	}
}

void Bolt::World::AddGameObject(GameObject* gameObject)
{
	gameObjects.push_back(gameObject);
}

void Bolt::World::Clear(SDL_Renderer*& renderer)
{
	for (auto& GO : gameObjects) {
		SpriteComp* sprite = GO->GetComponent<SpriteComp>();
		if (sprite != nullptr) {
			sprite->Clear(renderer);
		}
	}
}

Bolt::GameObject* Bolt::World::CreateNewGameObject()
{
	GameObject* gameObject = new GameObject();
	AddGameObject(gameObject);
	return gameObject;
}
