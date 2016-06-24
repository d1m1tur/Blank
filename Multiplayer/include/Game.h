#ifndef GAME_H
#define GAME_H

#include "includes.h"

class Game
{
    public:
        Game();
        int Execute();

        SDL_Renderer* Renderer; //Our Renderer for the game
        SDL_Window* Window; //Our main game window
        SDL_Surface* Icon;
        SDL_Event Event; //For handling events

    protected:

    private:

        bool running;
        bool full_screen;

        bool Init();
        bool LoadContent();

        void OnEvent(SDL_Event* Event);
        void Loop();
        void Render();
        void Exit();

        Client User;
        Client User2;

};

#endif // GAME_H
