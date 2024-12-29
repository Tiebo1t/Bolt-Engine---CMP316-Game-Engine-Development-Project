#pragma once
#include "RenderSystem.h"
#include "TexturedRectangle.h"
#include "Components.h"

namespace Bolt
{

	class SpriteComp : public Components
	{
	public:
		SpriteComp(GameObject* owner);
		virtual ~SpriteComp();
		void Start() override;
		void Update() override;
		void Render();

	private:
		TexturedRectangle* sprite;
		SDL_Renderer* renderer;

	};

}


