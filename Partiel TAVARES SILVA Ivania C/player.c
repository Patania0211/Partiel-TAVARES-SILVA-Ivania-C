#include "player.h"

int drawPlayer(Player player, SDL_Renderer* renderer){
    //Function handling the displaying of the player on the screen
	SDL_Rect playerRect = { player.x, player.y, player.w, player.h };

	SDL_SetRenderDrawColor(renderer, 155, 1, 224, 1);
	SDL_RenderFillRect(renderer, &playerRect);

    return 0;
}

int movePlayer(Player* player) {
    //Function handling the player movement
    const Uint8* state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_W]) {
        (int)player->y -= (int)player->velocity;
    }
    if (state[SDL_SCANCODE_S]) {
        (int)player->y += (int)player->velocity;
    }
    if (state[SDL_SCANCODE_D]) {
        (int)player->x += (int)player->velocity;
    }
    if (state[SDL_SCANCODE_A]) {
        (int)player->x -= (int)player->velocity;
    }
    
    return 0;
}