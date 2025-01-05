#pragma once
#include <SDL3/SDL.h>
#include <string>

namespace Bolt
{

	class TexturedRectangle
	{
	public:
		// On construction, recieves texture data 
		TexturedRectangle(SDL_Renderer*& renderer, std::string filepath);
		~TexturedRectangle();

		// Functions
		void setRectangleProperties(int x, int y, int w, int h);
		void Render(SDL_Renderer*& renderer);
		void UpdatePos();
	private:
		// Variables for storing images and creating rectangle
		SDL_Texture* tex;
		SDL_FRect* rect;
	};

}


