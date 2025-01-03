#include "Application.h"
#include <iostream>
#include "RenderSystem.h"

namespace Bolt
{

	Application::Application():renderSystem{new RenderSystem()}
	{
		std::cout << "construct";
		renderSystem = new RenderSystem();
		//sceneManager = new SceneManager();
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{

		//IMGUI_CHECKVERSION();
		//ImGUI::CreateContext();
		//ImGuiIO& io = ImGUI::GetIO(); (void)io;

		//renderSystem->createWindow();

		mainWindow = SDL_CreateWindow("Window", screenX, screenY, SDL_EVENT_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(mainWindow, NULL);
		if (renderer == NULL)
		{

			std::cout << "No renderer";

		}

		running = true;
		levelChange = false;

		world = std::make_unique<World>();
		world->Load();
		world->Start(renderer);

		screen = SDL_GetWindowSurface(mainWindow);

		while (running) {

			for (Layer* layer : layerstack)
			{
				layer->OnUpdate();
			}

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
						std::cout << "0 was pressed, new level loaded" << std::endl;

						world->Clear(renderer);
						world2 = std::make_unique<World2>();
						world2->Load();
						world2->Start(renderer);

						levelChange = true;
					}
				}
			}

		Update();
		Render();
		}
	}

	void Application::Render()
	{
		if (levelChange == false)
		{
			world->Render(renderer);
		}
		else
		{
			world2->Render(renderer);
		}
	}

	void Application::Update()
	{
		if (levelChange == false)
		{
			world->Update();
		}
		else
		{
			world2->Update();
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		layerstack.PushLayer(layer);
	}

}
