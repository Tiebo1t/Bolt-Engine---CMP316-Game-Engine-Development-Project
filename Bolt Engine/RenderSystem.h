#pragma once
#include "SDL3/SDL.h"
#include <iostream>

namespace Bolt
{
	class RenderSystem
	{

	public:
		RenderSystem();
		~RenderSystem();

		void createWindow();

	private:
		int screenX = 5000;
		int screenY = 5000;

		SDL_Renderer* renderer;
		SDL_Window* mainWindow;
	};
}
