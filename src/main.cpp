#include <iostream>
//#include <SDL/SDL.h>
#include <SDL2/SDL.h>

#include "RenderWindow.hpp"
#include "Entity.hpp"

int main(int argc, char* argv[]){
	
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL ERROR: "<< SDL_GetError() << std::endl;
	}

	RenderWindow window("lmao", 1280, 720);

	SDL_Texture* texture = window.loadTexture("res/Untitled.jpeg");	
	const Uint8 *keystate; 
	Entity lmaoEntity(100, 100, texture);

	float lmaox = lmaoEntity.getRect().x;
	float lmaoy = lmaoEntity.getRect().y;	

	bool gameRunnin= true;

	SDL_Event event;

	while(gameRunnin){
		while (SDL_PollEvent(&event)){
			switch(event.type){
				case SDL_QUIT:
					gameRunnin = false;	

				}	
			}
			window.clear();
			window.render(lmaoEntity);
			window.display();
			keystate = SDL_GetKeyboardState(NULL);
			if(keystate[SDL_SCANCODE_LEFT]){
				lmaox -= 2;
				lmaoEntity.setX(lmaox);
			}
			if(keystate[SDL_SCANCODE_RIGHT]){
				lmaox += 2;
				lmaoEntity.setX(lmaox);
			}
			if(keystate[SDL_SCANCODE_UP]){
				lmaoy -= 2;
				lmaoEntity.setY(lmaoy);
			}
			if(keystate[SDL_SCANCODE_DOWN]){
				lmaoy += 2;
				lmaoEntity.setY(lmaoy);
			}
		}

		

		window.cleanUp();
	}

	
