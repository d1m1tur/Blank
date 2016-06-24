#include "Game.h"

void Game::GameLoop()
{
    while(gameIsRunning)
    {
        Game::CheckForEvents(); // check for events

        Game::Render(); // render

        SDL_Delay(1000/60); // delay
    }
}
