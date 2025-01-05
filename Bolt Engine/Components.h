#pragma once
#include "SDL3/SDL.h"
#include <iostream>

namespace Bolt
{

	class GameObject;
	class Components
	{
	public:
		Components(GameObject* owner);
		virtual ~Components();
		virtual void Start(SDL_Renderer*& renderer, int posx, int posy, int heightx, int heighy, std::string spriteTex);
		virtual void Update();
		virtual void Render();

	private:
		GameObject* gameObject;
	};


}


