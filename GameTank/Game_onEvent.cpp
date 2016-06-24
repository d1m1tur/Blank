#include "Game.h"

void Game::onEvent(SDL_Event* event){
    if(event->type == SDL_QUIT){
        running = false;
    }
    if(event->type == SDL_KEYDOWN){

    }
}
