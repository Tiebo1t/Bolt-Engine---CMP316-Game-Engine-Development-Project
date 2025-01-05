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

		//renderSystem->createWindow();

		mainWindow = SDL_CreateWindow("Window", screenX, screenY, SDL_EVENT_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(mainWindow, NULL);
		if (renderer == NULL)
		{

			std::cout << "No renderer";

		}

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;

		ImGui_ImplSDL3_InitForSDLRenderer(mainWindow, renderer);
		ImGui_ImplSDLRenderer3_Init(renderer);

		running = true;
		levelChange = false;

		world = std::make_unique<World>();
		world2 = std::make_unique<World2>();

		gameState.setCurrentState(State::Level1);
		Load(1);

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

				ImGui_ImplSDL3_ProcessEvent(&event);

				if (event.key.down)
				{
					if (event.key.key == BOLT_0) // https://www.youtube.com/watch?v=EBHmMmiVtCk&list=PLvv0ScY6vfd-p1gSnbQhY7vMe2rng0IL0&index=11 accessed: 27/12/24
					{
						std::cout << "0 was pressed, new level loaded" << std::endl;

						if (gameState.getCurrentState() == State::Level1)
						{
							Unload(1);
							Load(2);
							gameState.setCurrentState(State::Level2);
						}
						else if (gameState.getCurrentState() == State::Level2)
						{
							Unload(2);
							Load(1);
							gameState.setCurrentState(State::Level1);
						}

						//world->Clear(renderer);
						//world2->Load();
						//world2->Start(renderer);

						//if (levelChange == false)
						//{
						//	Load(2);
						//	Unload(1);

						//	levelChange = true;
						//}
						//else if (levelChange == true)
						//{
						//	Load(1);
						//	Unload(2);

						//	levelChange = false;
						//}
					}
				}
			}

			//switch (gameState.getCurrentState())
			//{
			//case (State::Level1):
			//	world->Load();
			//	world->Start(renderer);
			//	break;
			//case (State::Level2):
			//	world2->Load();
			//	world2->Start(renderer);
			//	break;
			//}

			ImGui_ImplSDLRenderer3_NewFrame();
			ImGui_ImplSDL3_NewFrame(); 
			ImGui::NewFrame();

			ImGui::Begin("Editor");

			ImGui::Text("Editor");

			ImGui::End();

			ImGui::Render();

			//SDL_RenderClear(renderer);

			Update(gameState.getCurrentState());
			Render(gameState.getCurrentState());

			ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer);
		}

		ImGui_ImplSDLRenderer3_Shutdown();
		ImGui_ImplSDL3_Shutdown();
		ImGui::DestroyContext();
	}

	void Application::Render(State s)
	{

		switch (s)
		{
		case (State::Level1):
			world->Render(renderer);
			break;
		case (State::Level2):
			world2->Render(renderer);
			break;
		}

		//if (s == State::Level1)
		//{
		//	world->Render(renderer, spritePos);
		//}
		//else
		//{
		//	world2->Render(renderer, spritePos);
		//}

	}

	void Application::Update(State s)
	{

		switch (s)
		{
		case (State::Level1):
			world->Update();
			break;
		case (State::Level2):
			world2->Update();
			break;
		}

		//if (s == State::Level1)
		//{
		//	world->Update();
		//}
		//else
		//{
		//	world2->Update();
		//}

	}

	void Application::Load(int worldNumber)
	{

		switch (worldNumber)
		{
		case (1):
			world->Load();
			world->Start(renderer);
			break;
		case(2):
			world2->Load();
			world2->Start(renderer);
			break;
		}

		//if (worldNumber == 1)
		//{
		//	world->Load();
		//	world->Start(renderer);
		//}
		//else if (worldNumber == 2)
		//{
		//	world2->Load();
		//	world2->Start(renderer);
		//}
	}

	void Application::Unload(int worldNumber)
	{
		switch (worldNumber)
		{
		case (1):
			world->Clear(renderer);
			break;
		case(2):
			world2->Clear(renderer);
			break;
		}

		//if (worldNumber == 1)
		//{
		//	world->Clear(renderer);
		//}
		//else if (worldNumber == 2)
		//{
		//	world2->Clear(renderer);
		//}
	}

	void Application::PushLayer(Layer* layer)
	{
		layerstack.PushLayer(layer);
	}

}
