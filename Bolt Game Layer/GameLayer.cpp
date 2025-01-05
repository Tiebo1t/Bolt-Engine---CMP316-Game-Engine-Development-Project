#include <Bolt.h>
#include <iostream>
#include "GameLayer.h"

class ExampleLayer : public Bolt::Layer
{
public:
	ExampleLayer() : Layer() {} // This layer doesn't do anything currently

	void OnUpdate() override
	{
	}

	void OnEvent(SDL_Event& event) override
	{
	}

};

class Game : public Bolt::Application
{
public:
	Game() 
	{
		PushLayer(new ExampleLayer()); // Creates a new layer on the layer stack
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
	return new Game();

}

