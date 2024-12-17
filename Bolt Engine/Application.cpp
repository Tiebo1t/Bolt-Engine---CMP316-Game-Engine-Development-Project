#include "Application.h"
#include <iostream>
#include "RenderSystem.h"

namespace Bolt
{

	Application::Application():renderSystem{new RenderSystem()}
	{
		std::cout << "construct";
		renderSystem = new RenderSystem();
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{

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
