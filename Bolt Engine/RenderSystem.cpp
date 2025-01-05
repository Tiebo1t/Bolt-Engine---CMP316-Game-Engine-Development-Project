#include "RenderSystem.h"

Bolt::RenderSystem::RenderSystem()
{
}

Bolt::RenderSystem::RenderSystem(SDL_Renderer*& renderer)
{
	std::cout << "Construct";
}

Bolt::RenderSystem::~RenderSystem()
{

}

void Bolt::RenderSystem::Draw(TexturedRectangle* sprite, SDL_Renderer*& renderer) // Used to render all sprite components
{
	// Renders and shows the current sprite
	sprite->Render(renderer); 

	SDL_RenderPresent(renderer);
}

void Bolt::RenderSystem::Clear(SDL_Renderer*& renderer)
{
	// Clears the screen 
	SDL_RenderClear(renderer);
}