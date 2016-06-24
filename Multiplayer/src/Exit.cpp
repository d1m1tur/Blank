#include "Game.h"

void Game::Exit()
{
    User.Disconnect();
    delete(&User);

    SDL_FreeSurface(Icon);
    SDL_DestroyWindow(Window);
    SDL_DestroyRenderer(Renderer);

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
