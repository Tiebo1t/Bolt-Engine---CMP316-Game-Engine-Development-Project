#include "World2.h"

Bolt::World2::World2()
{
}

Bolt::World2::~World2()
{
}

void Bolt::World2::Load()
{
	// Setting up all characters in world
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
	std::string img;

	int i = 0;
	img = "images/coolguy.bmp"; // Assigns image coolguy to both sprites
	for (auto& GO : gameObjects) { // Loops all gameobjects checking if they have a sprite component
		SpriteComp* sprite = GO->GetComponent<SpriteComp>();
		if (sprite != nullptr) {
			sprite->Start(renderer, posx[i], posy[i], heightx[i], heighty[i], img); // Calls start setting up each sprite with their corresponding data

			if (i == gameObjects.size()) i = 0; // Resets i if it reaches the end of all gameobjects
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
	// adds gameobjects to array
	gameObjects.push_back(gameObject);
}

void Bolt::World2::Clear(SDL_Renderer*& renderer)
{
	// Stops rendering all gameobjects
	for (auto& GO : gameObjects) {
		SpriteComp* sprite = GO->GetComponent<SpriteComp>();
		if (sprite != nullptr) {
			sprite->Clear(renderer);
		}
	}
}

Bolt::GameObject* Bolt::World2::CreateNewGameObject()
{
	// Adds new gameobjects to array
	GameObject* gameObject = new GameObject();
	AddGameObject(gameObject);
	return gameObject;
}
