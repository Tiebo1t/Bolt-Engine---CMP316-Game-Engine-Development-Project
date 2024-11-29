#pragma once
#include "Core.h"
#include "RenderSystem.h"
#include "SDL3/SDL.h"

namespace Bolt
{

	class BOLT_ENGINE_API Application // DLL created here
	{
	private:
		RenderSystem* renderSystem;

	public:
		Application();
		virtual ~Application();

		void Run();
		void Render();
	};

	// Will be defined in client
	Application* CreateApplication();

}



