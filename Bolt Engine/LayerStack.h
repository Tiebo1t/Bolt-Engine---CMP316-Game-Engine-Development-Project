#pragma once
#include "Core.h"
#include "Layer.h"
#include <vector>

namespace Bolt
{
	class BOLT_ENGINE_API LayerStack // Defines LayerStack class as a part of the engine dll
	{
	public:
		LayerStack();
		~LayerStack();

		// Defines functions for layer stack operations
		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);

		// Stores vector iterators for the beginning and end of the layer stack
		std::vector<Layer*>::iterator begin() { return layers.begin(); }
		std::vector<Layer*>::iterator end() { return layers.end(); }
	private:
		// Stores the layers vector and where the layerInsert is located in that vector
		std::vector<Layer*> layers;
		std::vector<Layer*>::iterator layerInsert;
	};
}


