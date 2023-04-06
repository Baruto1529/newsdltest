#pragma once 

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity{
public:
	Entity(float _x, float _y, SDL_Texture* _tex);
	float getX();
	float getY();
	void setX(float newX);
	void setY(float newY);
	SDL_Texture* getTex();
	SDL_Rect getRect();

private:
	float x, y;
	SDL_Rect currFrame;
	SDL_Texture* tex;

};