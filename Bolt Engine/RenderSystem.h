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
		int screenX = 1280;
		int screenY = 720;

		SDL_Renderer* renderer;
		SDL_Window* mainWindow;
	};
}