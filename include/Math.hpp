#pragma once

#include <SDL2/SDL.h>


class Vector2f{	
	
	public:
		Vector2f(float _x, float _y);

		float px, py;	
};

Vector2f::Vector2f(float _x, float _y):px(_x),py(_y){}