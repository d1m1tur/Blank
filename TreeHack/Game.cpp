#include "Game.h"

Game::Game()
{
    //ctr

    Window = NULL;
    Background = NULL;
    Splash = NULL;

    R1 = NULL;
    R2 = NULL;
    R3 = NULL;
    R4 = NULL;
    R5 = NULL;
    R6 = NULL;

    Icon = NULL;
    Running = true;
    LeftButtonPressed = false;
    dragOne = false;
    sunny = true;
    Fullscreen = false;

    lineX1 = 560;
    lineY1 = 0;
    lineX2 = 560;
    lineY2 = 480;

    water = 1.12;
    desert = 1;
    ocean = 1.24;

    Kx = 1;
    Ky = 1;

    fertilize = 1;
    beenDrop = false;

    currentKapka = 0;
    currentRubbish = 0;
    chorbi = 0;
    timeRub = 0;
    level = 0;

    Frame = 0;
}

int Game::OnExecute()
{
    cout<<"Execute"<<endl;

    if(OnInit() == false)
    {
        return -1;
    }

    cout<<"Init = true"<<endl;

    while(Running)
    {
    cout<<"Running = true\n"<<endl;

        while(SDL_PollEvent(&Event))
        {
            cout<<"Event = true"<<endl;
            OnEvent(&Event);
        }

        cout<<"\nLoop phase start"<<endl;
        OnLoop();
        cout<<"Loop phase end\n"<<endl;

        cout<<"\nRender phase start"<<endl;
        OnRender();
        cout<<"Render phase End\n"<<endl;



        //system("cls");
    }

    cout<<"Cleaning started"<<endl;
    Cleanup();
    cout<<"Cleaning ended"<<endl;

    return 0;
}

int main(int argc, char* argv[])
{
    Game theGame;

    return theGame.OnExecute();
}
