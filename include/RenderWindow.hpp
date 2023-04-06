#pragma once 

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"
class RenderWindow 
{
public:
	RenderWindow(const char* name, int w, int h);
	SDL_Texture* loadTexture(const char* filename);
	void cleanUp();
	void render(Entity &_entity);
	void clear();
	void display();
private: 
	SDL_Renderer* renderer;
	SDL_Window* window;

};