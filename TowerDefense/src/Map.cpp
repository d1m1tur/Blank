#include "Map.h"
#include "Game.h"

Map::Map()
{
    hoverTile = NULL;
    Tileset_Image = NULL;
    building = false;
}

Map::~Map()
{
    //dtor
}

bool Map::LoadTileSet()
{
    int firstPar;
    int secondPar;
    char spliter;

    //Checks if the image is loaded correctly
    if(Tileset_Image == NULL)
    {
        cout<<"Tile set Image not loaded!"<<endl;
        return false;
    }

    //Checks if the map file is loaded correctly
    if(loadMap == NULL)
    {
        cout<<"Map not loaded!"<<endl;
        return false;
    }

    //Load the map array from a file
    for(int y = 0; y < MAP_Y; y ++)
    {
        for(int x = 0; x < MAP_X; x ++)
        {
            loadMap >> firstPar;
            loadMap >> spliter;
            loadMap >> secondPar;

            //Creates a tile from the given arguments
            tile_map[y][x].LoadTile(x, y, firstPar, secondPar);
        }
    }

    return true;
}

void Map::RenderMap(SDL_Renderer* Rend)
{
    for(int i = 0; i < MAP_X; i ++)
    {
        for(int j = 0; j < MAP_Y; j ++)
        {
            if(tile_map[i][j].tileProperty == 0) continue; // Don't Render if the tile is disabled

            tile_map[i][j].DrawTile(Rend, Tileset_Image); //Draw the current tile
        }
    }
}

TILE* Map::GetHoverTile()
{
    int Mx = 0;
    int My = 0;

    //Gets the mouse X && Y
    SDL_GetMouseState(&Mx, &My);

    //If its out of the map returns NULL
    if(Mx < 0 || Mx > MAP_X * TILE_WIDTH)
        return NULL;
    if(My < 0 || My > MAP_Y * TILE_HEIGHT)
        return NULL;

    //Find the tile coordinates
    int tileX = Mx / TILE_WIDTH;
    int tileY = My / TILE_HEIGHT;

    //Returns a pointer to the hovered tile
    return &tile_map[tileY][tileX];
}

bool Map::OnHover(SDL_Renderer* Rend)
{
    //If the building menu is up don't get a new hover tile
    if(building == true)
    {
        return false;
    }

    //Gets a pointer to the hovered tile ... if no tile is hovered it returns false
    if((hoverTile = GetHoverTile()) == NULL)
    {
        cout<<"Mouse out of the map"<<endl;
        return false;
    }

    //Check the pointed tile properties ... if its disabled it return false
    if(hoverTile->tileProperty == 0)
    {
        cout<<"Tile is disabled"<<endl;
        return false;
    }

    //Changes the hovered tile to a hovered image
    Game::Draw(Rend, Hover_Image, hoverTile->xCoord, hoverTile->yCoord, TILE_WIDTH, TILE_HEIGHT, SDL_FLIP_NONE);

    return true;
}

bool Map::BuildTower(SDL_Renderer* Rend)
{
    if(hoverTile == NULL)
        return false;

    int Mx = 0;
    int My = 0;

    SDL_GetMouseState(&Mx, &My);

    int imgX = hoverTile->xCoord - TILE_WIDTH;
    int imgY = hoverTile->yCoord - TILE_HEIGHT;

    if(Mx < imgX || Mx > imgX + 3 * TILE_WIDTH) building = false;
    if(My < imgY || My > imgY + 3 * TILE_HEIGHT) building = false;

    if(building == false)
        return false;

    Game::Draw(Rend, BuildMenu_Image, imgX, imgY, 3 * TILE_WIDTH, 3 * TILE_HEIGHT, SDL_FLIP_NONE);

    return true;
}

