#pragma once
#include "SDL3/SDL.h"
#include <string>
#include <unordered_map>

namespace Bolt
{

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


