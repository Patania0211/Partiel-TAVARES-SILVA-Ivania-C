#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "food.h"

int quit = 0;
Player player = { 100,100,12,12,2 };

int main(int argc, char* argv[])
{

    Food food = { randX, randY, 20,20 };

    // init sdl
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Erreur SDL INIT failed\n");
        return -1;
    }
    //creer une fenetre avec sdl
    SDL_Window* window = SDL_CreateWindow("Pink square",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        800, 600, SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        printf("Erreur creation de la fenetre SDL\n");
        SDL_Quit();
        return -1;
    }

    // Creer le systeme de rendu
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL)
    {
        printf("Erreur creation rendu SDL");
        SDL_Quit();
        return -1;
    }
    while (!quit)
    {
        quit = closeWindow(window);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // RGB: White
        SDL_RenderClear(renderer);
        // update rendu
        drawPlayer(&player,renderer);
        movePlayer(&player);
        createFood(food, renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }

    return 0;
}

int closeWindow(SDL_Window* window) {

    SDL_Event event;

    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            return 1;
        }
    }
    return 0;
}