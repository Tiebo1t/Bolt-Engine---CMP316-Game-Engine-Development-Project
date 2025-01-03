#pragma once
#include "SDL3/SDL.h"

namespace Bolt
{

	class GameObject;
	class Components
	{
	public:
		Components(GameObject* owner);
		virtual ~Components();
		virtual void Start(SDL_Renderer*& renderer, int posx, int posy, int heightx, int heighy);
		virtual void Update();
		virtual void Render();

	private:
		GameObject* gameObject;
	};


}


