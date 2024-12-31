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

		//IMGUI_CHECKVERSION();
		//ImGUI::CreateContext();
		//ImGuiIO& io = ImGUI::GetIO(); (void)io;

		renderSystem->createWindow();
		running = true;

		world = std::make_unique<World>();

		world->Load();

		while (running) {

			while (SDL_PollEvent(&event)) // https://www.youtube.com/watch?v=FwRfH2bA48M&list=PLvv0ScY6vfd-p1gSnbQhY7vMe2rng0IL0&index=10 accessed: 27/12/24
			{
				if (event.type == SDL_EVENT_QUIT)
				{
					running = false;
				}
				if (event.key.down)
				{
					if (event.key.key == BOLT_0) // https://www.youtube.com/watch?v=EBHmMmiVtCk&list=PLvv0ScY6vfd-p1gSnbQhY7vMe2rng0IL0&index=11 accessed: 27/12/24
					{
						std::cout << "0 was pressed" << std::endl;
					}
				}

			}

		Render();
		}
	}

	void Application::Render()
	{
		renderSystem->Render();

		world->Render();
	}

}
