#pragma once
#include "GameObject.h"
#include "Components.h"
#include "SpriteComp.h"
#include "WorldTemplate.h"

namespace Bolt
{
	class World2 : public WorldTemplate
	{
	public:
		World2();
		~World2();
		void Load() override;
		void Start(SDL_Renderer*& renderer) override;
		void Render(SDL_Renderer*& renderer);
		void Update() override;
		void AddGameObject(GameObject* go) override;
		void Clear(SDL_Renderer*& renderer) override;
		GameObject* CreateNewGameObject() override;

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
