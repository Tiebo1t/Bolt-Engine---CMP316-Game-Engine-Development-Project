#include "World.h"

Bolt::World::World()
{
}

Bolt::World::~World()
{
}

void Bolt::World::Load()
{
	// Creates 2 character gameobjects with sprites
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
	std::string img; // image filepath

	// Not exactly a practical way of getting the images, positions and sizes of each sprite
	// Checks all gameobjects (which all contain sprites right now) and assigns each ones size, images and positions based off i

	int i = 0;
	for (auto& GO : gameObjects) { // Loops all gameobjects checking if they have a sprite component
		SpriteComp* sprite = GO->GetComponent<SpriteComp>(); 
		if (sprite != nullptr) {
			if (i == 0) img = "images/coolguy.bmp"; // Assigns image coolguy to sprite 1
			else if (i == 1) img = "images/notcoolguy.bmp"; // Assigns image notcoolguy to sprite 2
			sprite->Start(renderer, posx[i], posy[i], heightx[i], heighty[i], img); // Calls start setting up each sprite with their corresponding data

			if (i == gameObjects.size()) i = 0; // Resets i if it reaches the end of all gameobjects
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
	// Adds new gameobjects to the gameobjects array
	gameObjects.push_back(gameObject);
}

void Bolt::World::Clear(SDL_Renderer*& renderer)
{
	// Loops all gameobjects and stops rendering them
	for (auto& GO : gameObjects) {
		SpriteComp* sprite = GO->GetComponent<SpriteComp>();
		if (sprite != nullptr) {
			sprite->Clear(renderer);
		}
	}
}

Bolt::GameObject* Bolt::World::CreateNewGameObject()
{
	// Creates a new instance of a gameobject and adds it to the array of gameobjects
	GameObject* gameObject = new GameObject();
	AddGameObject(gameObject);
	return gameObject;
}
