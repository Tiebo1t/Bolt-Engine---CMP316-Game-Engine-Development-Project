#include "TexturedRectangle.h"
#include "ResourceManager.h"

Bolt::TexturedRectangle::TexturedRectangle(SDL_Renderer*& renderer, std::string filepath)
{
	// Textured rectangle is a rectangle with a surface (image) over it 
	rect = new SDL_FRect();
	SDL_Surface* retrievedSurface = ResourceManager::getInstance().getSurface(filepath); // Retrieves an instance of the resource manager where the texture is loaded and sets it to a surface
	tex = SDL_CreateTextureFromSurface(renderer, retrievedSurface); // applies the texture to the surface
}

Bolt::TexturedRectangle::~TexturedRectangle()
{
	SDL_DestroyTexture(tex);
}

void Bolt::TexturedRectangle::setRectangleProperties(int x, int y, int w, int h)
{
	// Sets up rectangles width and height as well as its x and y position on the screen
	rect->w = w;
	rect->h = h;
	rect->x = x;
	rect->y = y;
}

void Bolt::TexturedRectangle::Render(SDL_Renderer*& renderer)
{
	// Applies the texture over the rectangle
	SDL_RenderTexture(renderer, tex, NULL, rect); 
}

void Bolt::TexturedRectangle::UpdatePos()
{

}
