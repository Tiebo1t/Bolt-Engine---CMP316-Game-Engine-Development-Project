#pragma once
#include "Core.h"
#include "SDL3/SDL.h"

namespace Bolt
{
	// Layer based off of The Cherno's Hazel Engine layer implementation here: https://www.youtube.com/watch?v=_Kj6BSfM6P4&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=13
	// Layer is defined as an abstract class to be overwritten by other created layers.
	class BOLT_ENGINE_API Layer // Imported into the engine dll
	{
	public:
		Layer();
		virtual ~Layer();

		// Functions to be overwritten
		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(SDL_Event& event) {}

	};
}

