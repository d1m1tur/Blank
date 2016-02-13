#ifndef MAP_H
#define MAP_H

#include "TILE.h"
#include "Includes.h"

#define MAP_X 16
#define MAP_Y 16

class Map
{
    public:
        Map();
        virtual ~Map();


        ifstream loadMap;

        bool building;

        TILE* hoverTile;

        TILE tile_map[MAP_X][MAP_Y];

        SDL_Texture* Tileset_Image;
        SDL_Texture* BuildMenu_Image;
        SDL_Texture* Hover_Image;

        TILE* GetHoverTile();

        bool LoadTileSet();
        bool OnHover(SDL_Renderer* Rend);
        bool BuildTower(SDL_Renderer* Rend);

        void RenderMap(SDL_Renderer* Rend);

        void SetNexus();
        void SetSpawnPoint();


    protected:
    private:
};

#endif // MAP_H
