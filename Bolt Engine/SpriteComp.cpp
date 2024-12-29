#include "SpriteComp.h"
#include <iostream>

Bolt::SpriteComp::SpriteComp(GameObject* owner) : Components{ owner }
{
	sprite = new TexturedRectangle(renderer, "images/good.bmp");
}

Bolt::SpriteComp::~SpriteComp()
{
}

void Bolt::SpriteComp::Start()
{
	sprite->setRectangleProperties(1280 / 2, 720 / 2, 50, 50);
	// Create an instance of textured rectangle
}

void Bolt::SpriteComp::Render()
{
	// Call a draw function created in the render system
	std::cout << "Sprite is rendering" << std::endl;
	RenderSystem::getInstance().Draw(sprite);
	//renderSystem->Draw(sprite);
}

void Bolt::SpriteComp::Update()
{
}
