#include "LayerStack.h"

Bolt::LayerStack::LayerStack()
{
	layerInsert = layers.begin();
}

Bolt::LayerStack::~LayerStack()
{
	for (Layer* layer : layers)
	{
		delete layer;
	}
}

void Bolt::LayerStack::PushLayer(Layer* layer)
{
	layerInsert = layers.emplace(layerInsert, layer);
}

void Bolt::LayerStack::PopLayer(Layer* layer)
{
	auto it = std::find(layers.begin(), layers.end(), layer);
	if (it != layers.end())
	{
		layers.erase(it);
		layerInsert--;
	}
}
