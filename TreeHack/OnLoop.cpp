#include "Game.h"
#include "FPS.h"

void Game::OnLoop()
{
    CapFrameRate(30);

    static int rainDrop = 0;

    srand (time(NULL));

    rainDrop = rand() % 2 + 1;

    //Cursor

    SDL_SetCursor(SDL_GetDefaultCursor());

    //Drag Entities with mouse
    //MouseDrag(&Block);
    //MouseDrag(&Character);

    if(MouseDragReset(&Cloud) == true)
    {
        water += Raining;

        if(chorbi > 2)
        {
            CreateKapka();
            chorbi = 0;
        }
    }

    chorbi ++;

    if(MouseDragReset(&Fertilizer) == true)
    {
        if(Fertilizer.XPos + 30 < lineX1)
            beenDrop = true;
    }
    else if(beenDrop == true)
    {
        fertilize += BeRiching;
        beenDrop = false;
    }

    fertilize -= Disolving;

    // Water Function
    water -= Drying;

    for(int i = 0; i < maxKapki; i ++)
    {
        Kapka[i].YPos += 10 * Ky;

        if(Kapka[i].YPos > 430 * Ky && Kapka[i].falling == true)
        {
            Kapka[i].falling = false;
            if(rainDrop == 1)
            {
                cout<<"Kapka 1"<<endl;
                Mix_PlayChannel( -1, rain_drop1, 0 );
            }
            else if (rainDrop == 2)
            {
                cout<<"Kapka 2"<<endl;
                Mix_PlayChannel( -1, rain_drop2, 0 );
            }

        }
    }

    if(water < desert) water = desert;
    if(water > ocean) water = ocean;

    if(fertilize < 1) fertilize = 1;
    if(fertilize > 10) fertilize = 10;

    waterPointer.x = waterX * water;
    fertilizePointer.x = fertilizeX * fertilize;

    for(int i = 0; i < 10; i ++)
    {
        if(Rubish[i].falling == true)
        {
            if(MouseDragReset(&Rubish[i]) == true)
            {
                int mouseX = 0;
                int mouseY = 0;

                SDL_GetMouseState(&mouseX, &mouseY);

                if(RecycleBin.Hover(mouseX, mouseY) == true)
                {
                    Rubish[i].falling = false;
                    dragOne = false;
                    Rubish[i].draggable = false;
                    if(Rubish[i].Image == R3 || Rubish[i].Image == R5)
                        Mix_PlayChannel( -1, throw_trash1, 0 );
                    else
                        Mix_PlayChannel( -1, throw_trash2, 0 );
                }
            }
            cout<<"Xpos: "<<Rubish[i].XPos<<" Ypos: "<<Rubish[i].YPos<<endl;
        }
    }

    if(timeRub == 200)
    {
        RandomRubbish();
        timeRub = 0;
    }

    timeRub ++;

    /*int help = 4;
    MouseDrag(&Level[help]);
    cout<<Level[help].XPos<<" "<<Level[help].YPos<<endl;*/

}

void Game::MouseDrag(Entity *object)
{
    //Cursor on Hover

    if(dragOne == true && object->draggable == false)
        return;

    int mouseX = 0;
    int mouseY = 0;

    SDL_GetMouseState(&mouseX, &mouseY);

    if(object->Hover(mouseX, mouseY) == true)
    {
        SDL_SetCursor(Cursor);

        if(LeftButtonPressed == true)
            object->draggable = true;
    }

    if(LeftButtonPressed == false)
        object->draggable = false;

    if(object->draggable == true)
    {
        object->XPos = mouseX - object->Width / 2;
        object->YPos = mouseY - object->Height / 2;
        SDL_SetCursor(DragCursor);
        dragOne = true;
    }
    else
        dragOne = false;
}

bool Game::MouseDragReset(Entity *object)
{
    //Cursor on Hover

    if(dragOne == true && object->draggable == false)
        return false;

    int mouseX = 0;
    int mouseY = 0;

    SDL_GetMouseState(&mouseX, &mouseY);

    if(object->Hover(mouseX, mouseY) == true)
    {
        SDL_SetCursor(Cursor);

        if(LeftButtonPressed == true)
            object->draggable = true;
    }

    if(LeftButtonPressed == false)
        object->draggable = false;

    if(object->draggable == true)
    {
        object->XPos = mouseX - object->Width / 2;
        object->YPos = mouseY - object->Height / 2;
        SDL_SetCursor(DragCursor);
        dragOne = true;
        return true;
    }
    else
    {
        dragOne = false;
        object->XPos = object->defaultX * Kx;
        object->YPos = object->defaultY * Ky;
        return false;
    }

}

void Game::CreateKapka()
{
    if(Kapka[currentKapka].falling == false && Cloud.XPos + 30 < lineX1 * Kx)
    {
        Kapka[currentKapka].CreateEntity(Cloud.XPos + 20 * Kx, Cloud.YPos + 20 * Ky, 20 * Kx, 40 * Ky);
        Kapka[currentKapka].falling = true;
        currentKapka ++;
    }

    if(currentKapka > 48)
    {
        currentKapka = 0;
    }
}

void Game::RandomRubbish()
{
    srand (time(NULL));

    int trashX = rand() % 470 + 30;
    int trashY = rand() % 240 + 200;
    int trashW = 0;
    int trashH = 0;

    int trash = rand() % 6 + 1;


    switch (trash)
    {
        case 1:
            Rubish[currentRubbish].Image = R1;
            trashW = 25;
            trashH = 50;
            break;
        case 2:
            Rubish[currentRubbish].Image = R2;
            trashW = 32;
            trashH = 43;
            break;
        case 3:
            Rubish[currentRubbish].Image = R3;
            trashW = 38;
            trashH = 45;
            break;
        case 4:
            Rubish[currentRubbish].Image = R4;
            trashW = 40;
            trashH = 43;
            break;
        case 5:
            Rubish[currentRubbish].Image = R5;
            trashW = 48;
            trashH = 60;
            break;
        case 6:
            Rubish[currentRubbish].Image = R6;
            trashW = 50;
            trashH = 47;
            break;
    }
    Rubish[currentRubbish].CreateEntity(trashX, trashY, trashW, trashH);
    Rubish[currentRubbish].falling = true;
    Rubish[currentRubbish].Responsive(Kx, Ky);
    currentRubbish ++;
    if(currentRubbish == 10)
        currentRubbish = 0;
}

void Game::MakeResponsive()
{
    //cout<<"Responsivness"<<endl;

    SDL_GetWindowSize(Window, &WindowWidth, &WindowHeight);

    float Window_Width = WindowWidth;
    float Window_Height = WindowHeight;

    Kx = Window_Width / MIN_WINDOW_X;
    Ky = Window_Height / MIN_WINDOW_Y;

    Cloud.Responsive(Kx, Ky);
    Sun.Responsive(Kx, Ky);
    Moon.Responsive(Kx, Ky);
    Tree.Responsive(Kx, Ky);
    Block.Responsive(Kx, Ky);
    Fertilizer.Responsive(Kx, Ky);
    Meter.Responsive(Kx, Ky);
    MeterF.Responsive(Kx, Ky);
    RecycleBin.Responsive(Kx, Ky);
    DayNight.Responsive(Kx, Ky);

    for(int i = 0; i < 10; i++)
        Rubish[i].Responsive(Kx, Ky);
    for(int i = 0; i < 5; i++)
        Level[i].Responsive(Kx, Ky);
    for(int i = 0; i < maxKapki; i++)
        Kapka[maxKapki].Responsive(Kx, Ky);
}
