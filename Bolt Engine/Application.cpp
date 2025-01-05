#include "Application.h"
#include <iostream>
#include "RenderSystem.h"

namespace Bolt
{

	Application::Application():renderSystem{new RenderSystem()}
	{
		std::cout << "construct"; // Creates a new instance of the render system on construction of the application
		renderSystem = new RenderSystem();
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{

		mainWindow = SDL_CreateWindow("Window", screenX, screenY, SDL_EVENT_WINDOW_SHOWN); // Defines main window size 
		renderer = SDL_CreateRenderer(mainWindow, NULL); // Creates renderer for the main window
		if (renderer == NULL)
		{

			std::cout << "No renderer";

		}

		IMGUI_CHECKVERSION(); // Sets up imgui by checking its version and creating a context of it
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io; // Retrieves imgui IO

		ImGui_ImplSDL3_InitForSDLRenderer(mainWindow, renderer); // Sets up imgui for use with SDL3 by providing the renderer and main window
		ImGui_ImplSDLRenderer3_Init(renderer);

		world = std::make_unique<World>(); // Creates unique pointers of the worlds
		world2 = std::make_unique<World2>();

		gameState.setCurrentState(State::Level1); // Sets the current game state to level 1 and loads level 1 data
		Load(1);

		screen = SDL_GetWindowSurface(mainWindow); // retrieves the surface of the main window

		while (running) { // Game Loop

			for (Layer* layer : layerstack) // Loops over all layers on the layer stack and updates them
			{
				layer->OnUpdate();
			}

			while (SDL_PollEvent(&event)) // https://www.youtube.com/watch?v=FwRfH2bA48M&list=PLvv0ScY6vfd-p1gSnbQhY7vMe2rng0IL0&index=10 accessed: 27/12/24
			{
				if (event.type == SDL_EVENT_QUIT) // Checks if window is closed, if so stop running app
				{
					running = false;
				}

				ImGui_ImplSDL3_ProcessEvent(&event); // Processes all events for imgui using the input from sdl

				if (event.key.down) // Checks if a key is pressed
				{
					// Checks if key 0 is pressed
					if (event.key.key == BOLT_0) // https://www.youtube.com/watch?v=EBHmMmiVtCk&list=PLvv0ScY6vfd-p1gSnbQhY7vMe2rng0IL0&index=11 accessed: 27/12/24
					{
						std::cout << "0 was pressed, new level loaded" << std::endl;

						// Checks if the current game state is level 1 or 2 and unloads the current level and loads the other level as well as changing the game state
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
					}
				}
			}

			ImGui_ImplSDLRenderer3_NewFrame(); // Tells imgui that a new frame has occoured
			ImGui_ImplSDL3_NewFrame(); 
			ImGui::NewFrame();

			ImGui::Begin("Editor"); // Creates the imgui interface with text "editor"

			ImGui::Text("Editor"); 
			ImGui::SliderInt("Sprite 1: X position", &spritePosX, 0, 1000);

			ImGui::End();

			ImGui::Render(); // Renders the imgui interface

			SDL_RenderClear(renderer); // Clears the renderer

			Update(gameState.getCurrentState()); // Updates and renders the current active level
			Render(gameState.getCurrentState());

			ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer); // Gives imgui draw data from the current frame from the renderer

			SDL_RenderPresent(renderer); // Presents the renderer
		}

		ImGui_ImplSDLRenderer3_Shutdown(); // Close ImGui and destroy its instance
		ImGui_ImplSDL3_Shutdown();
		ImGui::DestroyContext();

		SDL_DestroyWindow(mainWindow);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
	}

	void Application::Render(State s)
	{

		// Runs render on the current active world
		switch (s)
		{
		case (State::Level1):
			world->Render(renderer, &spritePosX);
			break;
		case (State::Level2):
			world2->Render(renderer);
			break;
		}

	}

	void Application::Update(State s)
	{

		// Runs update on the current active world
		switch (s)
		{
		case (State::Level1):
			world->Update();
			break;
		case (State::Level2):
			world2->Update();
			break;
		}

	}

	void Application::Load(int worldNumber)
	{

		// Loads and initialises the sprites for the current world
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

	}

	void Application::Unload(int worldNumber)
	{
		// Clears the renderer for each world
		switch (worldNumber)
		{
		case (1):
			world->Clear(renderer);
			break;
		case(2):
			world2->Clear(renderer);
			break;
		}

	}

	void Application::PushLayer(Layer* layer)
	{
		// If a new layer is created pushes it onto the layer stack
		layerstack.PushLayer(layer);
	}

}
