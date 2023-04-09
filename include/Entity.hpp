#pragma once 

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Math.hpp"

class Entity{
public:
	Entity(Vector2f _pos, SDL_Texture* _tex, int _W, int _h);
	float getX();
	float getY();
	Vector2f getPos();
	void setX(float newX);
	void setY(float newY);
	void setPos(float newX, float newY);
	SDL_Texture* getTex();
	SDL_Rect getRect();
	void move(const Uint8* _keystate, Entity* _lmao, float lmaox, float lmaoy);
	bool isTouching(Entity lmfao);

private:
	Vector2f pos;	
	float x, y;
	int w, h;
	SDL_Rect currFrame;
	SDL_Texture* tex;

};