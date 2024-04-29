#include "food.h"
#define MAXBULLETS 6

int RenderRect = 0;
int createFood(Food food, SDL_Renderer* renderer){
    SDL_Rect appleRect = {food.x, food.y, food.w, food.h};

    SDL_SetRenderDrawColor(renderer, 155, 10, 45, 1);
    SDL_RenderFillRect(renderer, &appleRect);
    return 0;
}