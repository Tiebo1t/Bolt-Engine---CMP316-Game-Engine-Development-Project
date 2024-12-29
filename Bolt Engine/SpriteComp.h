#pragma once
#include "RenderSystem.h"
#include "TexturedRectangle.h"
//#include "RenderSystem.h"

namespace Bolt
{

	class SpriteComp
	{
	public:
		SpriteComp();
		~SpriteComp();
		void Start();
		void Update();
		void Render();

	private:
		TexturedRectangle* sprite;
		SDL_Renderer* renderer;
		//RenderSystem* renderSystem;

	};

}


