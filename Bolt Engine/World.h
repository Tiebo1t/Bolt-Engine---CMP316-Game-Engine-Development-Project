#pragma once
#include "GameObject.h"
#include "Components.h"
#include "SpriteComp.h"

namespace Bolt
{
	class World
	{
	public:
		World();
		~World();
		void Render();
		void Update();
		void AddGameObject(GameObject* go);
		GameObject* CreateNewGameObject();

	private:
		std::vector<GameObject*> gameObjects;
	};

}

