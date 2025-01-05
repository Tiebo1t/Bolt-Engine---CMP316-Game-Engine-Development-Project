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

		void Run();
		void Render(State s);
		void Update(State s);
		void Load(int worldNumber);
		void Unload(int worldNumber);
		void PushLayer(Layer* layer);

		enum class GameStates {Level1, Level2};

	private:
		RenderSystem* renderSystem;
		//SceneManager* sceneManager;
		std::unique_ptr<World> world;
		std::unique_ptr<World2> world2;
		SDL_Event event;
		bool running;
		bool levelChange;
		LayerStack layerstack;
		GameState gameState;

		int screenX = 1280;
		int screenY = 720;

		SDL_Renderer* renderer;
		SDL_Window* mainWindow;
		SDL_Surface* screen;
	};

	// Will be defined in client
	BOLT_ENGINE_API Application* CreateApplication();

}



