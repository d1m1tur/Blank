#include "Game.h"

void Game::Render()
{
    SDL_RenderClear(renderer); // Cleat the renderer


    background.render(renderer); // render the background
    character.render(renderer);// render the character entity
    health_bar.render(renderer); // render the health bar
    list<dmgFloat>::iterator it = dmg_text.begin(); // iterator for the list of damage texts
    while(it != dmg_text.end() && dmg_text.size() > 0) // iterate trough all of them
    {
        if(!it->exist) // if it does not exist erase it from the list
            dmg_text.erase(it++);
        else // if it does
        {
            it->render(renderer); //render it
            ++it; // move to the next one
        }
    }


    SDL_RenderPresent(renderer); // Present the renderer to the window
}
