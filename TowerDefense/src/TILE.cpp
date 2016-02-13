#include "TILE.h"
#include "Game.h"

TILE::TILE()
{
    //ctor
}

TILE::~TILE()
{
    //dtor
}

void TILE::LoadTile(int x, int y, int prop, int xImg)
{
    xCoord = x * TILE_WIDTH;
    yCoord = y * TILE_HEIGHT;
    tileProperty = prop;
    tileSetCoord = xImg * TILE_WIDTH;
}

void TILE::DrawTile(SDL_Renderer* Rend, SDL_Texture* TileTemp)
{
    Game::Draw(Rend, TileTemp, xCoord, yCoord, TILE_WIDTH, TILE_HEIGHT, tileSetCoord, 0, TILE_WIDTH, TILE_HEIGHT, SDL_FLIP_NONE);
}

void TILE::SetNexus()
{
    tileProperty = 3;
    tileSetCoord = NEXUS * TILE_WIDTH;
}

void TILE::SetSpawnPoint()
{
    tileProperty = 4;
    tileSetCoord = SPAWNPOINT * TILE_WIDTH;
}
