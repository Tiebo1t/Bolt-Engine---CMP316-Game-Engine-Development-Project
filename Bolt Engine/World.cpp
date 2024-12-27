#include "World.h"

Bolt::World::World()
{
}

Bolt::World::~World()
{
}

void Bolt::World::Render()
{
	// Render all game objects with sprite components
}

void Bolt::World::Update()
{
	// Update all game objects
}

void Bolt::World::AddGameObject(GameObject* gameObject)
{
	gameObjects.push_back(gameObject); // ----------------- Dont think will work yet
}

Bolt::GameObject* Bolt::World::CreateNewGameObject()
{
	GameObject* gameObject = new GameObject();
	AddGameObject(gameObject);
	return gameObject;
}
