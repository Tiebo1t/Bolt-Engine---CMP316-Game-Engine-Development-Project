#include "GameObject.h"
#include "Components.h"

Bolt::GameObject::GameObject()
{
}

Bolt::GameObject::~GameObject()
{
}

void Bolt::GameObject::Start(SDL_Renderer*& renderer, int posx, int posy, int heightx, int heighy, std::string img)
{
	// Loops all components associated with the gameobject and initialises them
	for (auto& c : comps) {
		c->Start(renderer, posx, posy, heightx, heighy, img);
	}
}

void Bolt::GameObject::Update()
{
	// Loops all components and updates them
	for (auto& c : comps) {
		c->Update();
	}
}

void Bolt::GameObject::Render()
{
	// Loops all components and runs render on them
	for (auto& c : comps) {
		c->Render();
	}
}