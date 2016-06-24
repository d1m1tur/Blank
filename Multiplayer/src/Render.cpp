#include "Game.h"

void Game::Render()
{
    SDL_RenderClear(Renderer);

    User.Character.render(Renderer);

    if(User2.online)  User2.Character.render(Renderer);

    SDL_RenderPresent(Renderer);
}
