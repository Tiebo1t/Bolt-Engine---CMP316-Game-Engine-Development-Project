#pragma once
#include "GameObject.h"
#include "Components.h"
#include "SpriteComp.h"

namespace Bolt
{
	class World2
	{
	public:
		World2();
		~World2();
		void Load();
		void Start(SDL_Renderer*& renderer);
		void Render(SDL_Renderer*& renderer);
		void Update();
		void AddGameObject(GameObject* go);
		GameObject* CreateNewGameObject();

	private:
		std::vector<GameObject*> gameObjects;
		GameObject* character;
		GameObject* character2;

		int posx[2];
		int posy[2];
		int heightx[2];
		int heighty[2];
	};

}
