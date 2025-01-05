#pragma once
#include "Core.h"
#include "SDL3/SDL.h"
#include <imgui.h>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_sdlrenderer3.h>
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"
#include "World.h"
#include "World2.h"
#include "KeyCodes.h"
#include "Layer.h"
#include "LayerStack.h"
#include "GameState.h"

namespace Bolt
{
	class RenderSystem;
	class BOLT_ENGINE_API Application // DLL created here
	{
	public:
		Application();
		virtual ~Application();

		// Defining functions
		void Run();
		void Render(State s);
		void Update(State s);
		void Load(int worldNumber);
		void Unload(int worldNumber);
		void PushLayer(Layer* layer);

		// Sets up levels
		enum class GameStates {Level1, Level2};

	private:
		// Defining variables and pointers/instances of classes
		RenderSystem* renderSystem;
		std::unique_ptr<World> world;
		std::unique_ptr<World2> world2;
		SDL_Event event;
		bool running;
		LayerStack layerstack;
		GameState gameState;

		// Defines screen size
		int screenX = 1280;
		int screenY = 720;

		// Variable for editing sprite position in the x, to be used with imgui
		int spritePosX = 10;

		SDL_Renderer* renderer;
		SDL_Window* mainWindow;
		SDL_Surface* screen;
	};

	// Application is defined by the client (GameLayer)
	BOLT_ENGINE_API Application* CreateApplication();

}



