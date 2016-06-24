#include "Game.h"
#include "ServerConnection.h"

//Check for events

void Game::CheckForEvents()
{
    //if there was a user input
    if(SDL_PollEvent(&event))
    {
        //If the window's quit button is pressed exit the game
        if (event.type == SDL_QUIT)
            gameIsRunning = false;

        if(event.key.type == SDL_KEYDOWN)
        {

            //If the escape button is pressed exit the game
            if (event.key.keysym.sym == SDLK_ESCAPE)
                gameIsRunning = false;

            //If the up arrow key was pressed move up
            if (event.key.keysym.sym == SDLK_UP)
            {
                Entity::getEntity("Player")->moveTo(0, -0.01);
            }

            //If the down arrow key was pressed move down
            if (event.key.keysym.sym == SDLK_DOWN)
            {
                Entity::getEntity("Player")->moveTo(0, 0.01);
            }

            //If the left arrow key was pressed move left
            if (event.key.keysym.sym == SDLK_LEFT)
            {
                Entity::getEntity("Player")->moveTo(-0.01, 0);
            }

            //If the right arrow key was pressed move right
            if (event.key.keysym.sym == SDLK_RIGHT)
            {
                Entity::getEntity("Player")->moveTo(0.01, 0);
            }

            //If 'r' was pressed reset player
            if (event.key.keysym.sym == SDLK_r)
            {
                character.respawn();
                health_bar.setCurrency(character.getStats().hp);
            }


        }

        //If the left mouse button was clicked
        if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
        {
            int dmg = 4;

            int x , y;
            SDL_GetMouseState(&x, &y);

            float x_ = x;
            float y_ = y;

            x_ /= WINDOW_MAX_WIDTH;
            y_ /= WINDOW_MAX_HEIGHT;

            if(character.getState() && character.isHover())
            {
                character.takeDmg(dmg);
                dmgtxt.load(dmg, x_, y_);
                dmg_text.push_back(dmgtxt);
                health_bar.setCurrency(character.getStats().hp);
            }
        }


    }
}
