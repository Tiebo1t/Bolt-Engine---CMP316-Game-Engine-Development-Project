#include "TexturedRectangle.h"
#include "ResourceManager.h"

Bolt::TexturedRectangle::TexturedRectangle(SDL_Renderer*& renderer, std::string filepath)
{
	// Need to consider when to give up ownership of resources
	SDL_Surface* retrievedSurface = ResourceManager::getInstance().getSurface("./images/good.bmp");
	//SDL_Surface* surface = SDL_LoadBMP(filepath.c_str());
	tex = SDL_CreateTextureFromSurface(renderer, retrievedSurface);
	SDL_FRect* rect = new SDL_FRect();
}

Bolt::TexturedRectangle::~TexturedRectangle()
{
	SDL_DestroyTexture(tex);
}

void Bolt::TexturedRectangle::setRectangleProperties(int x, int y, int w, int h)
{
	rect->x = x;
	rect->y = y;
	rect->w = w;
	rect->h = h;
}

void Bolt::TexturedRectangle::update()
{
}

void Bolt::TexturedRectangle::render(SDL_Renderer*& renderer)
{
	SDL_RenderRect(renderer, rect);
}
