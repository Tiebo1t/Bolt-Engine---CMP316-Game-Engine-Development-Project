#include "World.h"

Bolt::World::World()
{
}

Bolt::World::~World()
{
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
