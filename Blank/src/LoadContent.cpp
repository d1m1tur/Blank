#include "Game.h"

bool Game::LoadContent()
{
    ///TEXTURES

    Map1.Tileset_Image = OnLoad(Renderer, "./Resources/Images/iso64x64.png");

    Map1.Hover_Image = OnLoad(Renderer, "./Resources/Images/HoverImage.png");

    Character.Image = OnLoad(Renderer, "./Resources/Images/ogre.png");

    if(Map1.Hover_Image == NULL)
    {
        return false;
    }

    if(Map1.Tileset_Image == NULL)
    {
        return false;
    }

    if(Character.Image == NULL)
    {
        return false;
    }

    SDL_SetTextureAlphaMod(Map1.Hover_Image, 100);

    ///MAPS

    Map1.loadMap.open("./Resources/Maps/temp.map");

    if(Map1.LoadTileSet() == false)
    {
        cout<<"Map not loaded"<<endl;
        Sleep(1000);
        return false;
    }

    return true;
}
