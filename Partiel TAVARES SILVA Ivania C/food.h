#pragma once
#include <SDL.h>

typedef struct Food {
	int x;
	int y;
	int w;
	int h;
} Food;


int createFood(Food food, SDL_Renderer* renderer);
