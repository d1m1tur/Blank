#include "Game.h"

void Game::onCleanup(){
    SDL_FreeSurface(imageSurface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(texture);
    IMG_Quit();
    SDL_Quit();
}
