#include "Game.h"

void Game::OnRender()
{
    static int framing = 0;

    SDL_RenderClear(Renderer);

    //cout<<"Kx = "<<Kx<<" Ky = "<<Ky<<endl;

    if(SplashScreen() == true)
      return;

    if(sunny == true)
        Background = backDay;
    else
        Background = backNight;

    Draw(Background, 0, 0, WindowWidth, WindowHeight, SDL_FLIP_NONE);

    //cout<<"Background"<<endl;

   // SDL_RenderDrawLine(Renderer, lineX1, lineY1, lineX2, lineY2);

    Draw(Meter.Image, Meter.XPos, Meter.YPos, Meter.Width, Meter.Height, Meter.Flip);

    Draw(MeterF.Image, MeterF.XPos, MeterF.YPos, MeterF.Width, MeterF.Height, MeterF.Flip);

    Draw(RecycleBin.Image, RecycleBin.XPos, RecycleBin.YPos, RecycleBin.Width, RecycleBin.Height, RecycleBin.Flip);

    Draw(DayNight.Image, DayNight.XPos, DayNight.YPos, DayNight.Width, DayNight.Height, DayNight.Flip);

    if(sunny == false)
    {
        Draw(MyMoon.Animate,
            Moon.XPos, Moon.YPos, Moon.Width, Moon.Height,
            MyMoon.width, MyMoon.height, MyMoon.Width, MyMoon.Height,
            Moon.Flip);
    }
    else
    {
        Draw(MySun.Animate,
            Sun.XPos, Sun.YPos, Sun.Width, Sun.Height,
            MySun.width, MySun.height, MySun.Width, MySun.Height,
            Sun.Flip);
    }

    Draw(MyTree.Animate,
            Tree.XPos, Tree.YPos, Tree.Width, Tree.Height,
            MyTree.width, MyTree.height, MyTree.Width, MyTree.Height,
            Tree.Flip);

    Draw(Level[level].Image, Level[level].XPos, Level[level].YPos, Level[level].Width, Level[level].Height, SDL_FLIP_NONE);

    for(int i = 0; i < maxKapki; i ++)
    {
        if(Kapka[i].falling == true)
            Draw(Kapchica, Kapka[i].XPos, Kapka[i].YPos, Kapka[i].Width, Kapka[i].Height, SDL_FLIP_NONE);
    }

    for(int i = 0; i < 10; i ++)
    {
        if(Rubish[i].falling == true)
            Draw(Rubish[i].Image, Rubish[i].XPos, Rubish[i].YPos, Rubish[i].Width, Rubish[i].Height, SDL_FLIP_NONE);
    }

    Draw(Cloud.Image, Cloud.XPos, Cloud.YPos, Cloud.Width, Cloud.Height, Cloud.Flip);

    Draw(Fertilizer.Image, Fertilizer.XPos, Fertilizer.YPos, Fertilizer.Width, Fertilizer.Height, Fertilizer.Flip);

    Draw(Kapchica, waterPointer.x * Kx, waterPointer.y * Ky, waterPointer.w * Kx, waterPointer.h * Ky, SDL_FLIP_NONE);

    Draw(Kapchica, fertilizePointer.x * Kx, fertilizePointer.y * Ky, fertilizePointer.w * Kx, fertilizePointer.h * Ky, SDL_FLIP_NONE);

    ///      Creating animation

    MySun.Animate = Sun.Image;
    MySun.Frames = 4;
    MySun.Height = 85;
    MySun.Width = 85;
    MySun.SpriteHeight = 85;
    MySun.SpriteWidth = 340;

    MyMoon.Animate = Moon.Image;
    MyMoon.Frames = 8;
    MyMoon.Height = 100;
    MyMoon.Width = 100;
    MyMoon.SpriteHeight = 100;
    MyMoon.SpriteWidth = 800;

    MyTree.Animate = Tree.Image;
    MyTree.Frames = 11;
    MyTree.Height = 330;
    MyTree.Width = 463;
    MyTree.SpriteHeight = 330;
    MyTree.SpriteWidth = 5093;

    if(framing == 3)
    {
        MyMoon.Animation();
        MySun.Animation();
        MyTree.Animation();
        framing = 0;
    }

    framing ++;

    SDL_RenderPresent(Renderer);
}

/// Draw Functions ...

bool Game::Draw(SDL_Texture* Temp,
                int x, int y, int w, int h,
                SDL_RendererFlip Flip)
{
    //Rectangle for Position
    SDL_Rect dstrect;

    //Texture is empty
    if(Temp == NULL)
    {
        return false;
    }

    dstrect.x = x;
    dstrect.y = y;
    dstrect.w = w;
    dstrect.h = h;


    //Draw on the screen
	SDL_RenderCopyEx(Renderer, Temp, NULL, &dstrect, 0, NULL, Flip);

	return true;
}

bool Game::Draw(SDL_Texture* Temp,
/*Location*/    int x, int y, int w, int h,
/*  Part  */    int x2, int y2, int w2, int h2,
                SDL_RendererFlip Flip)
{
    //Rectangle for position
    SDL_Rect dstrect;
    //Rectangle for part of an image
    SDL_Rect srtrect;

    //Texture is empty
    if(Temp == NULL)
    {
        return false;
    }

    dstrect.x = x;
    dstrect.y = y;
    dstrect.w = w;
    dstrect.h = h;

    srtrect.x = x2;
    srtrect.y = y2;
    srtrect.w = w2;
    srtrect.h = h2;


    //Draw on the screen
	SDL_RenderCopyEx(Renderer, Temp, &srtrect, &dstrect, 0, NULL, Flip);

	return true;
}

bool Game::SplashScreen()
{
    static int startup = 0;
    static bool spScreen = true;

    if(spScreen == false)
        return false;

    //cout<<"SplashScreen  "<<startup<<endl;

    Draw(Splash, 0, 0, WindowWidth, WindowHeight, SDL_FLIP_NONE);

    startup++;

    if(startup >= 100) spScreen = false;

    SDL_RenderPresent(Renderer);

    return true;
}
