#include <Bolt.h>
#include <iostream>
#include "GameLayer.h"

class ExampleLayer : public Bolt::Layer
{
public:
	ExampleLayer() : Layer() {}

	void OnUpdate() override
	{
		// try implementing imgui, if not maybe try audio system
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
		PushLayer(new ExampleLayer()); // Doesnt do anything right now
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
	//return new Bolt_Game_Layer();
	return new Game();

}

