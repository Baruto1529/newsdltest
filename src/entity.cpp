#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.hpp"	

Entity::Entity(float _x, float _y, SDL_Texture* _tex):x(_x), y(_y),tex(_tex){

	currFrame.x = 0;
	currFrame.y = 0;
	currFrame.w = 100; 
	currFrame.h = 100; 
}

float Entity::getX(){
	return x;
}

float Entity::getY(){
	return y; 
}

SDL_Texture* Entity::getTex(){
	return tex;
}

SDL_Rect Entity::getRect(){
	return currFrame;
}

void Entity::setX(float newX){
	x = newX * 2;
}

void Entity::setY(float newY){
	y = newY * 2;
}