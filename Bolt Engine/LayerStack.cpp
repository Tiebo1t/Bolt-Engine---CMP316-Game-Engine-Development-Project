#include "LayerStack.h"

Bolt::LayerStack::LayerStack() // Sets layerInsert to the beginning of the stack
{
	layerInsert = layers.begin();
}

Bolt::LayerStack::~LayerStack()
{
	for (Layer* layer : layers) // On destruction, deletes all layers
	{
		delete layer;
	}
}

void Bolt::LayerStack::PushLayer(Layer* layer) // When a new layer is pushed, layerInsert is pushed up in memory by the amount the new layer is equal to
{
	layerInsert = layers.emplace(layerInsert, layer);
}

void Bolt::LayerStack::PopLayer(Layer* layer) // Removes a layer from the stack and moves layerInsert back down to the location in memory of the previous layer
{
	auto it = std::find(layers.begin(), layers.end(), layer);
	if (it != layers.end())
	{
		layers.erase(it);
		layerInsert--;
	}
}
