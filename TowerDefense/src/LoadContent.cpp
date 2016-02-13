#include "Game.h"

bool Game::LoadContent()
{
    ///TEXTURES

    Map1.Tileset_Image = OnLoad(Renderer, "./Resources/Images/tileset.png");

    Map1.BuildMenu_Image = OnLoad(Renderer, "./Resources/Images/buildmenu.png");

    Map1.Hover_Image = OnLoad(Renderer, "./Resources/Images/HoverImage.png");

    if(Map1.Hover_Image == NULL)
    {
        return false;
    }

    if(Map1.Tileset_Image == NULL)
    {
        return false;
    }

    if(Map1.BuildMenu_Image == NULL)
    {
        return false;
    }

    SDL_SetTextureAlphaMod(Map1.Hover_Image, 100);
    SDL_SetTextureAlphaMod(Map1.BuildMenu_Image, 256/2);

    ///MAPS

    Map1.loadMap.open("./Resources/Maps/map1.map");

    if(Map1.LoadTileSet() == false)
    {
        cout<<"Map not loaded"<<endl;
        Sleep(1000);
        return false;
    }

    return true;
}
