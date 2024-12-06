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
	renderer = SDL_CreateRenderer(mainWindow, "Window");
	if (renderer == NULL)
	{

		std::cout << "No renderer";

	}
	//SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFC, 0xFF);
}
