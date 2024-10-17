#pragma once
#include "Core.h"

namespace Bolt
{

	class BOLT_ENGINE_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// Will be defined in client
	Application* CreateApplication();

}



