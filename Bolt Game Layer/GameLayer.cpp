#include <Bolt.h>
#include <iostream>
#include "GameLayer.h"

class ExampleLayer : public Bolt::Layer
{

public:
	ExampleLayer() : Layer() {}

	void OnUpdate() override
	{
		std::cout << "Game Layer updating" << std::endl;
	}

};

class Game : public Bolt::Application
{
public:
	Game() 
	{
		PushLayer(new ExampleLayer());
	}
	~Game()
	{
	}
};

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

