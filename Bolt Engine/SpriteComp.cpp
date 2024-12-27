#include "SpriteComp.h"
#include <iostream>

Bolt::SpriteComp::SpriteComp()
{
}

Bolt::SpriteComp::~SpriteComp()
{
}

void Bolt::SpriteComp::Start()
{

}

void Bolt::SpriteComp::Render()
{
	// Call a draw function to be created in the render system, will need to instantiate an instance of the render system
	std::cout << "Sprite is rendering" << std::endl;
}

void Bolt::SpriteComp::Update()
{
}
