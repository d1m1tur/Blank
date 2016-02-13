#include "Map.h"
#include "Game.h"

void Map::SetNexus()
{
    hoverTile = GetHoverTile();

    hoverTile->SetNexus();
}

void Map::SetSpawnPoint()
{
    hoverTile = GetHoverTile();

    hoverTile->SetSpawnPoint();
}

