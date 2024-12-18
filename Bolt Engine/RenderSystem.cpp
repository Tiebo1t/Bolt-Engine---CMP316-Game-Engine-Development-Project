#include "RenderSystem.h"

Bolt::RenderSystem::RenderSystem()
{
	std::cout << "Construct";

	//SDL_GetBasePath();

	texturedRect = new TexturedRectangle(renderer, "images/good.bmp");
	texturedRect->setRectangleProperties(100, 100, 0, 0);
	//rect = new SDL_FRect();

	//rect = new SDL_FRect();

	//rect->w = 100;
	//rect->h = 100;
	//rect->y = 0;
	//rect->x = 0;
}

Bolt::RenderSystem::~RenderSystem()
{

}

void Bolt::RenderSystem::createWindow()
{
	mainWindow = SDL_CreateWindow("Window", screenX, screenY, 0);
	renderer = SDL_CreateRenderer(mainWindow, NULL);
	if (renderer == NULL)
	{

		std::cout << "No renderer";

	}

	screen = SDL_GetWindowSurface(mainWindow);
}

void Bolt::RenderSystem::Render()
{

	SDL_RenderClear(renderer);

	//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	//SDL_RenderPoint(renderer, 1280 / 2, 720 / 2);

	//SDL_RenderRect(renderer, rect);

	image = SDL_LoadBMP("images/good.bmp"); // https://www.youtube.com/watch?v=YlwDwC4H47s&list=PLvv0ScY6vfd-p1gSnbQhY7vMe2rng0IL0&index=14

	SDL_BlitSurface(image, NULL, screen, NULL);

	SDL_DestroySurface(image);
	SDL_UpdateWindowSurface(mainWindow);

	//texturedRect->render(renderer);
	
	SDL_RenderPresent(renderer);
	
}
