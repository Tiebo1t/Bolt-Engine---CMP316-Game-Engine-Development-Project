#include "Application.h"
#include <iostream>
#include "RenderSystem.h"

namespace Bolt
{

	Application::Application():renderSystem{new RenderSystem()}
	{
		std::cout << "construct";
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		std::cout << "hi";

		std::cout << "yes";

		//renderSystem = new RenderSystem();
		renderSystem->createWindow();

		while (true);

	}

	void Application::Render()
	{
		
	}

}
