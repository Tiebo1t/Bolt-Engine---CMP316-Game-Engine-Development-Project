#pragma once
#include "SDL3/SDL.h"
#include <string>
#include <unordered_map>

namespace Bolt
{
	// Resource manager based off of Mike Shah's SDL resource manager implementation here: https://www.youtube.com/watch?v=_DGIRmHUtwQ
	class ResourceManager
	{
	private:
		ResourceManager();
		~ResourceManager();

		std::unordered_map<std::string, SDL_Surface*> surfaces;
	public:
		static ResourceManager& getInstance();

		SDL_Surface* getSurface(std::string filepath);

	};

}


