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

		//renderSystem = new RenderSystem();
		renderSystem->createWindow();

		while (true) {
			Render();
		}

	}

	void Application::Render()
	{
		renderSystem->Render();
	}

}
