#include "Application.h"
#include <iostream>

namespace Bolt
{

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		std::cout << "hi";

		std::cout << "yes";

		renderSystem->createWindow();

		while (true);

	}

	void Application::Render()
	{
		
	}

}
