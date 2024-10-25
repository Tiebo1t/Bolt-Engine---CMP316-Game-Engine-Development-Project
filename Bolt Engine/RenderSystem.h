#pragma once
#include "SDL3/SDL.h"

namespace Bolt
{
	class RenderSystem
	{

		RenderSystem();
		~RenderSystem();

		void createWindow();

	private:
		int screenX = 500;
		int screenY = 500;

	};
}
