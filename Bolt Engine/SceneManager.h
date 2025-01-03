#pragma once
#include <memory>
#include "WorldTemplate.h"

namespace Bolt
{
	// Doesnt work right now
	class SceneManager
	{
	public:
		SceneManager();
		~SceneManager();

		void Load(std::unique_ptr<WorldTemplate> world, SDL_Renderer*& renderer)
		{ 
			world->Load();
			world->Start(renderer);
		}

		void UnLoad(std::unique_ptr<WorldTemplate> world, SDL_Renderer*& renderer)
		{

		}
	};
}

