#include <Bolt.h>
#include <iostream>
#include "GameLayer.h"

//class Bolt_Game_Layer : public Bolt::Application
//{
//
//public:
//	Bolt_Game_Layer() : Bolt::Application()
//	{
//		std::cout << "Construct game layer" << std::endl;
//	}
//
//	~Bolt_Game_Layer()
//	{
//	}
//
//};

Bolt_Game_Layer::Bolt_Game_Layer() : Bolt::Application()
{
	std::cout << "Construct game layer" << std::endl;
}

Bolt_Game_Layer::~Bolt_Game_Layer()
{
}

Bolt::Application* Bolt::CreateApplication()
{

	// Creates a new instance of our game layer on heap
	return new Bolt_Game_Layer();

}

