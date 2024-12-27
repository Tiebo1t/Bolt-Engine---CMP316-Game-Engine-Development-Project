#pragma once
#include "Core.h"
#include "SDL3/SDL.h"

namespace Bolt
{
	class RenderSystem;
	class BOLT_ENGINE_API Application // DLL created here
	{
	private:
		RenderSystem* renderSystem;
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



