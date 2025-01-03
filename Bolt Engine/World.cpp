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
}

void Bolt::World::Start(SDL_Renderer*& renderer)
{
	for (auto& GO : gameObjects) {
		SpriteComp* sprite = GO->GetComponent<SpriteComp>();
		if (sprite != nullptr) {
			sprite->Start(renderer, 1280 / 2, 720 / 2, 50, 50);
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

Bolt::GameObject* Bolt::World::CreateNewGameObject()
{
	GameObject* gameObject = new GameObject();
	AddGameObject(gameObject);
	return gameObject;
}
