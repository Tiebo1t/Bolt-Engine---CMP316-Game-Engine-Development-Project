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
		~RenderSystem();

		void createWindow();
		void Render();
		void Draw();
	private:
		int screenX = 1280;
		int screenY = 720;

		SDL_Renderer* renderer;
		SDL_Window* mainWindow;
		SDL_FRect* rect;
		SDL_Surface* screen;
		SDL_Surface* image;
		SDL_Texture* texture;
		TexturedRectangle* texturedRect;
		TexturedRectangle* texturedRect2;
		TexturedRectangle* texturedRect3;
		DeltaTime* deltaTime;
	};
}