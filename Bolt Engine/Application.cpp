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

		SDL_CreateWindow("Window", 600, 800, 0);

		while (true);


	}

}
