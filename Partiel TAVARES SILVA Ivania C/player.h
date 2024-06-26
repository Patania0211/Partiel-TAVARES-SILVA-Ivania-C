#pragma once
#include <SDL.h>


typedef struct Player {
	int x;
	int y;
	int w;
	int h;
	int velocity;
}Player;

int drawPlayer(Player player, SDL_Renderer* renderer);
int movePlayer(Player* player);