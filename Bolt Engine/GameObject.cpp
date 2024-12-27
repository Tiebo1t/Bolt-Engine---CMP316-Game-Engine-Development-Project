#include "GameObject.h"
#include "Components.h"

Bolt::GameObject::GameObject()
{
}

Bolt::GameObject::~GameObject()
{
}

void Bolt::GameObject::Start()
{
	for (auto& c : comps) {
		c->Start();
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