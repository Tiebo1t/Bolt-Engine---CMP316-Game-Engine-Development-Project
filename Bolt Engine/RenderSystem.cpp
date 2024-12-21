#include "RenderSystem.h"

Bolt::RenderSystem::RenderSystem()
{
	std::cout << "Construct";

	//SDL_GetBasePath();

	//rect = new SDL_FRect();

	//rect->w = 50;
	//rect->h = 50;
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

	texturedRect = new TexturedRectangle(renderer, "images/good.bmp");
	texturedRect->setRectangleProperties(50, 50, 0, 0);

	texturedRect2 = new TexturedRectangle(renderer, "images/good.bmp");
	texturedRect2->setRectangleProperties(50, 50, 1280 / 2, 720 / 2);

	texturedRect3 = new TexturedRectangle(renderer, "images/good.bmp");
	texturedRect3->setRectangleProperties(50, 50, 1000, 600);

	deltaTime = new DeltaTime();
}

void Bolt::RenderSystem::Render()
{

	deltaTime->update();

	std::cout << deltaTime->getDeltaTime() << std::endl;

	SDL_RenderClear(renderer);

	texturedRect->render(renderer);

	//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	texturedRect2->render(renderer);

	texturedRect3->render(renderer);

	//image = SDL_LoadBMP("images/good.bmp"); // https://www.youtube.com/watch?v=YlwDwC4H47s&list=PLvv0ScY6vfd-p1gSnbQhY7vMe2rng0IL0&index=14

	//SDL_BlitSurface(image, NULL, screen, NULL);

	//SDL_DestroySurface(image);
	//SDL_UpdateWindowSurface(mainWindow);
	
	SDL_RenderPresent(renderer);
	
}
