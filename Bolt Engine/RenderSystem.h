#pragma once
#include "SDL3/SDL.h"
#include <iostream>
#include "TexturedRectangle.h"

namespace Bolt
{
	class RenderSystem
	{

	public:
		RenderSystem();
		~RenderSystem();

		void createWindow();
		void Render();
	private:
		int screenX = 1280;
		int screenY = 720;

		SDL_Renderer* renderer;
		SDL_Window* mainWindow;
		SDL_FRect* rect;
		TexturedRectangle* texturedRect;
	};
}