#include "Game.h"

void Game::OnEvent(SDL_Event* Event)
{
    if(Event->type == SDL_QUIT)
    {
        Running = false;
    }

    if(Event->type == SDL_WINDOWEVENT)
    {
        if(Event->window.event == SDL_WINDOWEVENT_RESIZED)
        {
            cout<<"Resized"<<endl;
            Sleep(1000);
            MakeResponsive();
        }
    }

    if(Event->type == SDL_KEYDOWN)
    {
        if(Event->key.keysym.sym == SDLK_ESCAPE)
        {
            Running = false;
        }

        if(Event->key.keysym.sym == SDLK_LEFT)
        {
            //Character.MoveLeft();
            level--;
            if(level < 0) level = 0;
        }

        if(Event->key.keysym.sym == SDLK_RIGHT)
        {
            //Character.MoveRight();
            level++;
            if(level > 4) level = 4;
        }

        if(Event->key.keysym.sym == SDLK_UP)
        {

        }

        if(Event->key.keysym.sym == SDLK_DOWN)
        {

        }

        if(Event->key.keysym.sym == SDLK_1)
        {
        }

        if(Event->key.keysym.sym == SDLK_2)
        {
        }

        if(Event->key.keysym.sym == SDLK_3)
        {
        }

        if(Event->key.keysym.sym == SDLK_4)
        {
        }

        if(Event->key.keysym.sym == SDLK_F11)
        {
            if(Fullscreen == false)
            {
                Fullscreen = true;
                SDL_SetWindowFullscreen(Window, SDL_WINDOW_FULLSCREEN_DESKTOP);
            }
            else
            {
                Fullscreen = false;
                SDL_SetWindowFullscreen(Window, SDL_WINDOW_MINIMIZED);
            }
        }

        if(Event->key.keysym.sym == SDLK_9)
        {
             //If there is no music playing
            if( Mix_PlayingMusic() == 0 )
            {
                //Play the music
                Mix_PlayMusic( wind, -1 );
            }
            //If music is being played
            else
            {
                //If the music is paused
                if( Mix_PausedMusic() == 1 )
                {
                    //Resume the music
                    Mix_ResumeMusic();
                }
                //If the music is playing
                else
                {
                    //Pause the music
                    Mix_PauseMusic();
                }
            }
        }

        if(Event->key.keysym.sym == SDLK_0)
        {
            //Stop the music
            Mix_HaltMusic();
        }
    }

    if(Event->type == SDL_MOUSEBUTTONDOWN)
    {
        if(Event->button.button == SDL_BUTTON_LEFT)
        {
            LeftButtonPressed = true;
            int mx = 0;
            int my = 0;

            SDL_GetMouseState(&mx, &my);

            if(DayNight.Hover(mx, my) == true)
            {
                sunny = !sunny;
            }
        }

        if(Event->button.button == SDL_BUTTON_RIGHT)
        {

        }
    }

    if(Event->type == SDL_MOUSEBUTTONUP)
    {
        if(Event->button.button == SDL_BUTTON_LEFT)
        {
            LeftButtonPressed = false;
        }

        if(Event->button.button == SDL_BUTTON_RIGHT)
        {

        }
    }


}
