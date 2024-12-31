#pragma once
#include "Core.h"
#include "SDL3/SDL.h"
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"
#include "World.h"
#include "KeyCodes.h"

namespace Bolt
{
	class RenderSystem;
	class BOLT_ENGINE_API Application // DLL created here
	{
	private:
		RenderSystem* renderSystem;
		std::unique_ptr<World> world;
		SDL_Event event;
		bool running;

	public:
		Application();
		virtual ~Application();

		void Run();
		void Render();
	};

	// Will be defined in client
	BOLT_ENGINE_API Application* CreateApplication();

}



