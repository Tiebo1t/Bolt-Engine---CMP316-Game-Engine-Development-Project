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
	for (auto& c : comps) {
		c->Start(renderer, posx, posy, heightx, heighy, img);
	}
}

void Bolt::GameObject::Update()
{
	for (auto& c : comps) {
		c->Update();
	}
}

void Bolt::GameObject::Render()
{
	for (auto& c : comps) {
		c->Render();
	}
}