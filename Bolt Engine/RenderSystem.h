#pragma once
#include "SDL3/SDL.h"
#include <iostream>
#include "TexturedRectangle.h"
#include "DeltaTime.h"

namespace Bolt
{
	class RenderSystem
	{

	public:
		RenderSystem();
		RenderSystem(SDL_Renderer*& renderer);
		~RenderSystem();

		// Returns an instance of the render system, and ensures it is only ever created once with the use of static
		static RenderSystem& getInstance()
		{
			static RenderSystem* instance = new RenderSystem();
			return *instance;
		}

		// Functions for drawing and clearing sprites from screen
		void Draw(TexturedRectangle* sprite, SDL_Renderer*& renderer);
		void Clear(SDL_Renderer*& renderer);

	private:

	};
}