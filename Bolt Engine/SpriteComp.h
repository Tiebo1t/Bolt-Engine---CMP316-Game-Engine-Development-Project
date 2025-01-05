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
		void Start(SDL_Renderer*& renderer, int posx, int posy, int heightx, int heighy, std::string spriteTex) override;
		void Update() override;
		void Render(SDL_Renderer*& renderer);
		void Clear(SDL_Renderer*& renderer);

	private:
		TexturedRectangle* sprite;

	};

}


