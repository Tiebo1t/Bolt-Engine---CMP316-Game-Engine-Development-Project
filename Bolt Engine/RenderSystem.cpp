#include "RenderSystem.h"

Bolt::RenderSystem::RenderSystem()
{
}

Bolt::RenderSystem::RenderSystem(SDL_Renderer*& renderer)
{
	std::cout << "Construct";

	texturedRect = new TexturedRectangle(renderer, "images/good.bmp");
	texturedRect->setRectangleProperties(50, 50, 50, 50);

	//texturedRect2 = new TexturedRectangle(renderer, "images/good.bmp");
	//texturedRect2->setRectangleProperties(1280 / 2, 720 / 2, 50, 50);

	//texturedRect3 = new TexturedRectangle(renderer, "images/good.bmp");
	//texturedRect3->setRectangleProperties(1000, 600, 50, 50);

	//deltaTime = new DeltaTime();
}

Bolt::RenderSystem::~RenderSystem()
{

}

void Bolt::RenderSystem::createWindow()
{

	// -- creating window was here

}

void Bolt::RenderSystem::Render(SDL_Renderer*& renderer)
{

	//deltaTime->update();

	//std::cout << deltaTime->getDeltaTime() << std::endl; // Delta time may not work properly yet, should be handled elsewhere

	//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	//SDL_RenderClear(renderer); -----

	//texturedRect->Render(renderer);

	//texturedRect2->Render(renderer);

	//texturedRect3->Render(renderer);

	//SDL_RenderFillRect(renderer, rect);

	//image = SDL_LoadBMP("images/good.bmp"); // https://www.youtube.com/watch?v=YlwDwC4H47s&list=PLvv0ScY6vfd-p1gSnbQhY7vMe2rng0IL0&index=14

	//SDL_BlitSurface(image, NULL, screen, NULL);

	//SDL_DestroySurface(image);
	//SDL_UpdateWindowSurface(mainWindow); ----
	
	//SDL_RenderPresent(renderer); ----- 
	
}

void Bolt::RenderSystem::Draw(TexturedRectangle* sprite, SDL_Renderer*& renderer) // Used to render all sprite components
{

	SDL_RenderClear(renderer); // Clears when draw is called

	sprite->Render(renderer); // FInd a way to put into render in renderSystem or similar

	SDL_UpdateWindowSurface(mainWindow);

	SDL_RenderPresent(renderer);
}

SDL_Renderer* Bolt::RenderSystem::getRenderer()
{
	return renderer;
}
