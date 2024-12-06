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
	bool isTrue = false;

	isTrue = SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	if (isTrue == false)
	{

		std::cout << "no colour";

	}
}

void Bolt::RenderSystem::Render()
{
	std::cout << "Render\n";
	SDL_RenderClear(renderer);
}
