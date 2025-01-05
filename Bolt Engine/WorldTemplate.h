#pragma once
#include "GameObject.h"
#include "Components.h"
#include "SpriteComp.h"

namespace Bolt
{
	class WorldTemplate
	{
	public:
		WorldTemplate();
		~WorldTemplate();
		virtual void Load();
		virtual void Start(SDL_Renderer*& renderer);
		virtual void Render(SDL_Renderer*& renderer, int* spritePos);
		virtual void Update();
		virtual void AddGameObject(GameObject* go);
		virtual void Clear(SDL_Renderer*& renderer);
		virtual GameObject* CreateNewGameObject();
	};

}