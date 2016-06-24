#include "Game.h"


bool Game::Init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) // Initialize everything we need for SDL
    {
        cerr << "Failed to initialize SDL: "<< SDL_GetError() << endl; // if there is an error catch it and prints on the console
        return false;
    }

    Icon = IMG_Load(PATH_ICON);

    if(Icon == NULL)
    {
        cerr << "Icon not loaded: " << SDL_GetError() << endl;
        return false;
    }

    //Window initialization
    Window = SDL_CreateWindow("Tanks", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if(Window == NULL)
    {
        cerr << "Window initialization error: " << SDL_GetError() << endl; // if there is an error catch it and prints on the console
        return false;
    }

    SDL_SetWindowMaximumSize(Window, WINDOW_MAX_X, WINDOW_MAX_Y);
    SDL_SetWindowMinimumSize(Window, WINDOW_MIN_X, WINDOW_MIN_Y);

    SDL_SetWindowIcon(Window, Icon);

    //Renderer initialization
    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(Renderer == NULL)
    {
        cerr << "Renderer initialization error: " << SDL_GetError() << endl; // if there is an error catch it and prints on the console
        return false;
    }

    if(!User.Connect("192.168.112.204"))
    {
        cerr << "Connection to game server failed" << endl;
        return false;
    }

    if(!LoadContent())
    {
        cerr << "Error loading files" << endl;
        return false;
    }

    return true;
}
