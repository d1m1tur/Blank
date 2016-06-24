#include "Game.h"
#include <stdio.h>
#include <iostream>
#include "SDL_image.h"
using namespace std;


SDL_Texture* LoadTexture(string filepath, SDL_Renderer* renderTarget){
    SDL_Texture* texture = nullptr;
    SDL_Surface* surface = IMG_Load(filepath.c_str());
    if(surface == nullptr){
        printf( "surface could not be loaded! SDL_Error: %s\n", IMG_GetError() );
    }
    else{
        texture = SDL_CreateTextureFromSurface(renderTarget, surface);
        if(texture==nullptr){
            cout<<"Error \n";
        }
    }
    SDL_FreeSurface(surface);
    return texture;
}

bool Game::onInit(){
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    else{
        //Create window
        window = SDL_CreateWindow( "TankGame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            return false;
        }
        else
        {
            //Get window surface

            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if(renderer == NULL){
                printf( "Renderer could not be created! SDL_Error: %s\n", SDL_GetError() );
                return false;
            }
            //texture=LoadTexture("grass_tiled.png", renderer);
            texture = LoadTexture("stepone.png",renderer);

        }

    }
    return true;
}
