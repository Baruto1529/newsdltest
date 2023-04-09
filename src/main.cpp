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
	
	Vector2f ipos(100, 100);
	Vector2f jpos(400, 500);
	Entity lmaoEntity(ipos, texture, 100, 100);
	Entity lmfaoEntity(jpos, texture, 1000, 50);	

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
			window.render(lmfaoEntity);
			window.display();
			keystate = SDL_GetKeyboardState(NULL);
			SDL_Rect LMAO = lmaoEntity.getRect(); 
			SDL_Rect lmfao = lmfaoEntity.getRect();
			bool collison = lmaoEntity.isTouching(lmfaoEntity);			
			if(keystate[SDL_SCANCODE_LEFT] && collison == true){
				lmaox -= 2;
				lmaoEntity.setX(lmaox);
			}
			if(keystate[SDL_SCANCODE_RIGHT] && collison == true){
				lmaox += 2;
				lmaoEntity.setX(lmaox);
			}
			if(keystate[SDL_SCANCODE_UP]&& collison == true){
				lmaoy -= 2;
				lmaoEntity.setY( lmaoy);
			}
			if(keystate[SDL_SCANCODE_DOWN]&& collison == true){
				lmaoy += 2;
				lmaoEntity.setY( lmaoy);
			}
			//lmaoEntity.move(keystate, &lmaoEntity, lmaox, lmaoy);
		}

		

		window.cleanUp();
	}

	
