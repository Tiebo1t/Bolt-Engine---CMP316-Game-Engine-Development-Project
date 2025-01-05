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
	//SDL_Renderer* renderer = RenderSystem::getInstance().getRenderer();
	sprite = new TexturedRectangle(renderer, spriteTex); // "images/good.bmp"
	sprite->setRectangleProperties(posx, posy, heightx, heighty); // Change to a transform component if have time
}

void Bolt::SpriteComp::Render(SDL_Renderer*& renderer)
{
	// Call a draw function created in the render system
	RenderSystem::getInstance().Draw(sprite, renderer);
	//renderSystem->Draw(sprite);
}

void Bolt::SpriteComp::Clear(SDL_Renderer*& renderer)
{
	RenderSystem::getInstance().Clear(renderer);
}

void Bolt::SpriteComp::Update()
{
	std::cout << "Sprites updating" << std::endl;
}
