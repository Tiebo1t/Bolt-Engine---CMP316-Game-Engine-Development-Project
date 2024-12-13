#include "RenderSystem.h"

Bolt::RenderSystem::RenderSystem()
{
	std::cout << "Construct";

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

}

void Bolt::RenderSystem::Render()
{

	SDL_RenderClear(renderer);

	std::cout << "Render\n";

	SDL_FRect* rect = new SDL_FRect();

	rect->w = 100;
	rect->h = 100;
	rect->y = 0;
	rect->x = 0;

	SDL_RenderRect(renderer, rect);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderPoint(renderer, 1280 / 2, 720 / 2);
	
	SDL_RenderPresent(renderer);
	
}
