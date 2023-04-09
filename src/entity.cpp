#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.hpp"	

Entity::Entity(Vector2f _pos, SDL_Texture* _tex, int _w, int _h):pos(_pos.px, _pos.py),tex(_tex){

	currFrame.x = 0;
	currFrame.y = 0;
	currFrame.w = _w; 
	currFrame.h = _h; 
}

float Entity::getX(){
	return pos.px;
}

float Entity::getY(){
	return pos.py; 
}

SDL_Texture* Entity::getTex(){
	return tex;
}

SDL_Rect Entity::getRect(){
	return currFrame;
}

Vector2f Entity::getPos(){
	return pos;
}

void Entity::setX(float newX){
	pos.px = newX * 2;
}

void Entity::setY(float newY){
	pos.py = newY * 2;
}

void Entity::setPos(float newX, float newY){
	pos.px = newX;
	pos.py = newY;
}

void Entity::move(const Uint8 * _keystate, Entity* _lmao, float lmaox, float lmaoy){

	if(_keystate[SDL_SCANCODE_LEFT] ){
				lmaox -= 2;
				_lmao->setX(lmaox);
	}
			if(_keystate[SDL_SCANCODE_RIGHT] ){
				lmaox += 2;
				_lmao->setX(lmaox);
			}
			if(_keystate[SDL_SCANCODE_UP]){
				lmaoy -= 2;
				_lmao->setY( lmaoy);
			}
			if(_keystate[SDL_SCANCODE_DOWN]){
				lmaoy += 2;
				_lmao->setY( lmaoy);
			}
}

bool Entity::isTouching(Entity lmfao){
	if(lmfao.getPos().px + lmfao.getRect().w < pos.px || pos.px > lmfao.getPos().px + lmfao.getRect().w || lmfao.getPos().py + lmfao.getRect().h < pos.py || pos.py > lmfao.getPos().px + lmfao.getRect().h)
	{
		return false;
	}
	else {
		return true;
	}

}