#include "Game.h"

void Game::OnRender()
{
    SDL_RenderClear(Renderer);

    //Render the map
    Map1.RenderMap(Renderer);

    Builder();

    //Checks what tile is hovered
    Map1.OnHover(Renderer);

    SDL_RenderPresent(Renderer);
}

/// Draw Functions ...

bool Game::Draw(SDL_Renderer* Rend,
                SDL_Texture* Temp,
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
	SDL_RenderCopyEx(Rend, Temp, NULL, &dstrect, 0, NULL, Flip);

	return true;
}

bool Game::Draw(SDL_Renderer* Rend,
                SDL_Texture* Temp,
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
	SDL_RenderCopyEx(Rend, Temp, &srtrect, &dstrect, 0, NULL, Flip);

	return true;
}

int Game::HoveredTower()
{
    if(Map1.hoverTile == NULL)
    {
        return 0;
    }

    int Mx = 0;
    int My = 0;

    SDL_GetMouseState(&Mx, &My);

    int buildX = Map1.hoverTile->xCoord - TILE_WIDTH;
    int buildY = Map1.hoverTile->yCoord - TILE_HEIGHT;

    Mx = Mx - buildX;
    My = My - buildY;

    int towerX = Mx / TILE_WIDTH;
    int towerY = My / TILE_HEIGHT;

    int currentTower = (1 + towerX) + (towerY * 3);

    switch(currentTower)
    {
        case 2:
            return TOWER1;
            break;

        case 4:
            return SELL;
            break;

        case 6:
            return TOWER2;
            break;

        case 8:
            return TOWER3;
            break;
    }

    return 0;
}

void Game::Builder()
{
    if(Map1.BuildTower(Renderer) == true && HoveredTower() > 0 && LeftButtonPressed == true)
    {
        Map1.hoverTile->tileSetCoord = HoveredTower() * TILE_WIDTH;
        Map1.hoverTile->tileProperty = 2;
    }
}
