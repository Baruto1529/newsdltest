#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"


RenderWindow::RenderWindow(const char* name, int w, int h){
    window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
    if(window == NULL){
        std::cout << "WIndow failed" << SDL_GetError() << std::endl;
	}	

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

}

void RenderWindow::cleanUp(){
    SDL_DestroyWindow(window);
}

SDL_Texture* RenderWindow::loadTexture(const char* filename){
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, filename);

    return texture;

}

void RenderWindow::clear(){
    SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity &_entity){
    SDL_Rect src;
    src.x = _entity.getRect().x;
    src.y = _entity.getRect().y;
    src.w = _entity.getRect().w;
    src.h = _entity.getRect().h;

    SDL_Rect dst;
    dst.x = _entity.getX(); 
    dst.y = _entity.getY();
    dst.h = _entity.getRect().h;
    dst.w = _entity.getRect().w; 

    SDL_RenderCopy(renderer, _entity.getTex(), &src, &dst);
}

void RenderWindow::display(){
    SDL_RenderPresent(renderer);
}


