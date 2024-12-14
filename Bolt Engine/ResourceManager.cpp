#include "ResourceManager.h"

Bolt::ResourceManager::ResourceManager()
{
}

Bolt::ResourceManager::~ResourceManager()
{
}

Bolt::ResourceManager& Bolt::ResourceManager::getInstance()
{
	static ResourceManager* managerInstance = new ResourceManager;// Use of static ensures resource manager is only ever instantiated once

	return *managerInstance; // Return pointer to avoid having additional error checks
}

SDL_Surface* Bolt::ResourceManager::getSurface(std::string filepath)
{

	auto search = surfaces.find(filepath); // Check through unordered map for any surfaces with an existing filename
	if (search != surfaces.end())
	{
		return surfaces[filepath]; // Return the surface with corresponding filepath
	}
	else
	{
		SDL_Surface* surface = SDL_LoadBMP(filepath.c_str()); // Add the surface to our map
		surfaces.insert(std::make_pair(filepath, surface));

		return surfaces[filepath];
	}

	return nullptr;
}
