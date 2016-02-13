#include "Game.h"
#include "OnAnimate.h"

bool Game::OnInit()
{
    //Initialize everything in SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return false;
    }

    database.open("D:\database.hack");

    //Creating Window             title ,Xpos,Ypos,Width,Height, settings
    if((Window = SDL_CreateWindow("Tree Hack", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, MIN_WINDOW_X, MIN_WINDOW_Y,
                                  SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE)) == NULL)
    {
        return false;
    }

    SDL_SetWindowMaximumSize(Window, MAX_WINDOW_X, MAX_WINDOW_Y);
    SDL_SetWindowMinimumSize(Window, MIN_WINDOW_X, MIN_WINDOW_Y);

    SDL_GetWindowSize(Window, &WindowWidth, &WindowHeight);

    Fullscreen = false;

    if((Icon = IMG_Load("./images/favicon.png")) == NULL)
    {
        return false;
    }


    SDL_SetWindowIcon(Window, Icon);

    //Initialize SDL_mixer
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;
    }

    // Creating Renderer
    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    int lineX1 = 560;
    int lineY1 = 0;
    int lineX2 = 560;
    int lineY2 = 480;

    //Creating Entities

    Sun.Flip = SDL_FLIP_NONE;
    Sun.Image = OnLoad("./images/sun.png");
    Sun.CreateEntity(445, 40, 85, 85);

    if(Sun.Image == NULL)
    {
        return false;
    }

    Moon.Flip = SDL_FLIP_NONE;
    Moon.Image = OnLoad("./images/moon.png");
    Moon.CreateEntity(440, 50, 85, 85);

    if(Moon.Image == NULL)
    {
        return false;
    }

    Tree.Flip - SDL_FLIP_NONE;
    Tree.Image = OnLoad("./images/Tree.png");
    Tree.CreateEntity(300, 130, 200, 100);

    if(Tree.Image == NULL)
    {
        return false;
    }

    Cloud.Flip = SDL_FLIP_NONE;
    Cloud.Image = OnLoad("./images/cloud.png");
    Cloud.CreateEntity(lineX1 + 10, 20, 60, 40);

    Fertilizer.Flip = SDL_FLIP_NONE;
    Fertilizer.Image = OnLoad("./images/fertilizer.png");
    Fertilizer.CreateEntity(lineX1 + 20, 80, 40, 40);

    Meter.Flip = SDL_FLIP_NONE;
    Meter.Image = OnLoad("./images/meter.png");
    Meter.CreateEntity(lineX1 - 130, 10, 110, 25);

    MeterF.Flip = SDL_FLIP_NONE;
    MeterF.Image = OnLoad("./images/fertily.png");
    MeterF.CreateEntity(10, 10, 110, 25);

    RecycleBin.Flip = SDL_FLIP_NONE;
    RecycleBin.Image = OnLoad("./images/recycleBin.png");
    RecycleBin.CreateEntity(lineX1 + 20, 480 - 70, 40, 50);

    DayNight.Flip = SDL_FLIP_NONE;
    DayNight.Image = OnLoad("./images/daynight.png");
    DayNight.CreateEntity(lineX1 + 3, 480 - 140, 80, 60);

    Level[0].Flip = SDL_FLIP_NONE;
    Level[0].Image = OnLoad("./images/c1.png");
    Level[0].CreateEntity(224, 264, 300, 300);

    Level[1].Flip = SDL_FLIP_NONE;
    Level[1].Image = OnLoad("./images/c2.png");
    Level[1].CreateEntity(225, 67, 200, 500);

    Level[2].Flip = SDL_FLIP_NONE;
    Level[2].Image = OnLoad("./images/c3.png");
    Level[2].CreateEntity(87, 108, 480, 440);

    Level[3].Flip = SDL_FLIP_NONE;
    Level[3].Image = OnLoad("./images/c4.png");
    Level[3].CreateEntity(28, 100, 400, 400);

    Level[4].Flip = SDL_FLIP_NONE;
    Level[4].Image = OnLoad("./images/c5.png");
    Level[4].CreateEntity(191, 175, 400, 300);


    for(int i = 0; i < 5; i++)
    {
        if(Level[i].Image == NULL)
        {
            return false;
        }
    }

    if(RecycleBin.Image == NULL)
    {
        return false;
    }

    if(Meter.Image == NULL)
    {
        return false;
    }

    if(MeterF.Image == NULL)
    {
        return false;
    }

    if(Cloud.Image == NULL)
    {
        return false;
    }

    if(DayNight.Image == NULL)
    {
        return false;
    }

    if(Fertilizer.Image == NULL)
    {
        return false;
    }

    cout<<"R1"<<endl;

    if((R1 = OnLoad("./images/r1.png")) == NULL)
    {
        cout<<SDL_GetError()<<endl;
        return false;
    }
    cout<<"R2"<<endl;

    if((R2 = OnLoad("./images/r2.png")) == NULL)
    {
        return false;
    }

    cout<<"R3"<<endl;

    if((R3 = OnLoad("./images/r3.png")) == NULL)
    {
        return false;
    }

    cout<<"R4"<<endl;

    if((R4 = OnLoad("./images/r4.png")) == NULL)
    {
        return false;
    }

    cout<<"R5"<<endl;

    if((R5 = OnLoad("./images/r5.png")) == NULL)
    {
        return false;
    }

    cout<<"R6"<<endl;

    if((R6 = OnLoad("./images/r6.png")) == NULL)
    {
        return false;
    }

    waterPointer.x = lineX1 - 128;
    waterPointer.y = 26;
    waterPointer.h = 15;
    waterPointer.w = 10;

    waterX = waterPointer.x;

    fertilizePointer.x = 10;
    fertilizePointer.y = 26;
    fertilizePointer.h = 15;
    fertilizePointer.w = 10;

    fertilizeX = fertilizePointer.x;

    ///#/////////////////////////////////////////////////

    if((backNight = OnLoad("./images/backNight.jpg")) == NULL)
    {
        return false;
    }

    if((backDay = OnLoad("./images/backDay.jpg")) == NULL)
    {
        return false;
    }

    Background = backDay;

    if((Splash = OnLoad("./images/TreeHack.png")) == NULL)
    {
        return false;
    }

    if((Kapchica = OnLoad("./images/Kapka.png")) == NULL)
    {
        return false;
    }

    //Load the music
    wind = Mix_LoadMUS( "./audio/wind.wav" );

    //If there was a problem loading the music
    if( wind == NULL )
    {
        cout<<"Wind wasnt loaded!!!"<<endl;
        Sleep(1000);
        return false;
    }

    //Load the sound effects

    rain_drop1 = Mix_LoadWAV("./audio/water-droplet-1.wav");
    rain_drop2 = Mix_LoadWAV("./audio/water-droplet-2.wav");
    throw_trash1 = Mix_LoadWAV("./audio/throw1.wav");
    throw_trash2 = Mix_LoadWAV("./audio/throw2.wav");

    //If there was a problem loading the sound effects

    if( throw_trash1 == NULL )
    {
        return false;
    }

    if( throw_trash2 == NULL )
    {
        return false;
    }

    if( rain_drop1 == NULL )
    {
        cout<<"rain_drop_1 not loaded"<<endl;
        return false;
    }

    if( rain_drop2 == NULL )
    {
        cout<<"rain_drop_2 not loaded"<<endl;
        return false;
    }

    if( (Cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND)) == NULL)
    {
        return false;
    }

    if( (DragCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZEALL)) == NULL)
    {
        return false;
    }

    //Check Renderer
    if(Renderer == NULL)
    {
        cout << SDL_GetError() << endl;
        return false;
    }

    database >> water;
    database >> fertilize;

    database.close();

    Mix_PlayMusic( wind, -1 );

    return true;
}

SDL_Texture* Game::OnLoad(char* File)
{
    SDL_Surface* Surf_Temp = NULL;
    SDL_Texture* Text_Return = NULL;

    if((Surf_Temp = IMG_Load(File)) == NULL)
    {
        return NULL;
    }

    if((Text_Return = SDL_CreateTextureFromSurface(Renderer, Surf_Temp)) == NULL)
    {
        return NULL;
    }

    SDL_FreeSurface(Surf_Temp);

    return Text_Return;
}
