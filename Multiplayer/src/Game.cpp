#include "Game.h"

Game::Game()
{
    running = true;
    full_screen = true;

    Window = NULL;
    Renderer = NULL;
    Icon = NULL;
}

int Game::Execute()
{
    running = Game::Init();

    while(running)
    {
        while(SDL_PollEvent(&Event))
        {
            Game::OnEvent(&Event);
        }

        Game::Loop();

        Game::Render();
    }

    Game::Exit();

    return 0;
}

int main(int argc, char *argv[])
{
    Game theGame;

    return theGame.Execute();
}
