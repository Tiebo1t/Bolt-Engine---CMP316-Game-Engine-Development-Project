#pragma once
#include "GameObject.h"
#include "Components.h"
#include "SpriteComp.h"
#include "WorldTemplate.h"

namespace Bolt
{
	class World : public WorldTemplate
	{
	public:
		// Functions inherited from world template to create a new world
		World();
		~World();
		void Load() override;
		void Start(SDL_Renderer*& renderer) override;
		void Render(SDL_Renderer*& renderer, int* spritex);
		void Update() override;
		void AddGameObject(GameObject* go) override;
		void Clear(SDL_Renderer*& renderer) override;
		GameObject* CreateNewGameObject() override;

	private:
		// Setting up character gameobjects
		std::vector<GameObject*> gameObjects;
		GameObject* character;
		GameObject* character2;

		// Arrays of data for sizes and positions for sprites
		int posx[2];
		int posy[2];
		int heightx[2];
		int heighty[2];
	};

}

