#include "SpriteComp.h"
#include <iostream>

Bolt::SpriteComp::SpriteComp(GameObject* owner) : Components{ owner }
{
}

Bolt::SpriteComp::~SpriteComp()
{
}

void Bolt::SpriteComp::Start(SDL_Renderer*& renderer, int posx, int posy, int heightx, int heighty, std::string spriteTex)
{
	// Create an instance of textured rectangle
	sprite = new TexturedRectangle(renderer, spriteTex); // The sprite is created as a textured rectangle
	sprite->setRectangleProperties(posx, posy, heightx, heighty); // Should have put this into a transform component, sets the sprites size, width and x and y position
}

void Bolt::SpriteComp::Render(SDL_Renderer*& renderer)
{
	// Call a draw function from the render system
	RenderSystem::getInstance().Draw(sprite, renderer); 
}

void Bolt::SpriteComp::Render(SDL_Renderer*& renderer, int* spritex) // Overloaded function allowing imgui slider to be used to update the x position of sprite 1 in world 1.
{
	// Call a draw function from the render system
	sprite->UpdatePos(spritex); // Changes the x position of sprite 1 in world 1 with imgui slider
	RenderSystem::getInstance().Draw(sprite, renderer);
}

void Bolt::SpriteComp::Clear(SDL_Renderer*& renderer)
{
	// Calls a clear function in the render system
	RenderSystem::getInstance().Clear(renderer);
}

void Bolt::SpriteComp::Update()
{

}
