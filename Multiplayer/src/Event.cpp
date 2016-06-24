#include "Game.h"

void Game::OnEvent(SDL_Event* Event)
{
    if(Event->type == SDL_QUIT)
    {
        running = false;
    }

    if(Event->type == SDL_WINDOWEVENT)
    {
        if(Event->window.event == SDL_WINDOWEVENT_RESIZED)
        {

        }
    }

    if(Event->type == SDL_KEYDOWN)
    {
        if(Event->key.keysym.sym == SDLK_ESCAPE)
        {
            running = false;
        }

        if(Event->key.keysym.sym == SDLK_F11)
        {
            if(!full_screen)
                SDL_SetWindowFullscreen(Window, SDL_WINDOW_FULLSCREEN_DESKTOP); // set full screen
            else
                SDL_SetWindowFullscreen(Window, SDL_WINDOW_MINIMIZED); // set minimized

            full_screen =  !full_screen;
        }

        if(Event->key.keysym.sym == SDLK_UP)
        {
            User.Character.movement(0, -10);
            User.SendData();
        }

        if(Event->key.keysym.sym == SDLK_DOWN)
        {
            User.Character.movement(0, 10);
            User.SendData();
        }

        if(Event->key.keysym.sym == SDLK_RIGHT)
        {

            User.Character.movement(10, 0);
            User.SendData();
        }

        if(Event->key.keysym.sym == SDLK_LEFT)
        {
            User.Character.movement(-10, 0);
            User.SendData();
        }

        if(Event->key.keysym.sym == SDLK_RETURN)
        {

        }
    }
}
