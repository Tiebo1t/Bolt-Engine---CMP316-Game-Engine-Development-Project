#include "TexturedRectangle.h"
#include "ResourceManager.h"

Bolt::TexturedRectangle::TexturedRectangle(SDL_Renderer*& renderer, std::string filepath)
{
	rect = new SDL_FRect();
	SDL_Surface* retrievedSurface = ResourceManager::getInstance().getSurface(filepath);
	tex = SDL_CreateTextureFromSurface(renderer, retrievedSurface);
}

Bolt::TexturedRectangle::~TexturedRectangle()
{
	SDL_DestroyTexture(tex);
}

void Bolt::TexturedRectangle::setRectangleProperties(int x, int y, int w, int h)
{
	rect->w = w;
	rect->h = h;
	rect->x = x;
	rect->y = y;
}

void Bolt::TexturedRectangle::Render(SDL_Renderer*& renderer)
{
	SDL_RenderTexture(renderer, tex, NULL, rect); 
}

void Bolt::TexturedRectangle::UpdatePos(int* spritePos)
{
	rect->x = spritePos[0];
	rect->y = spritePos[1];
}
