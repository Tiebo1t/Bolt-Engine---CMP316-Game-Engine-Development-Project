#pragma once
#include <SDL3/SDL.h>
#include <string>

namespace Bolt
{

	class TexturedRectangle
	{
	public:
		TexturedRectangle(SDL_Renderer*& renderer, std::string filepath);
		~TexturedRectangle();

		void setRectangleProperties(int x, int y, int w, int h);
		void Render(SDL_Renderer*& renderer);
		void UpdatePos(int* spritePos);
	private:
		SDL_Texture* tex;
		SDL_FRect* rect;
	};

}


