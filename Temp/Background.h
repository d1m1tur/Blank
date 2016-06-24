#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

#include <SDL.h> // include SDL

/*
    Struct for the background makes easier loading a background
    Works the same way as LGTexture.h but its more straight forward
*/

struct SDL_Background
{
    SDL_Texture* texture; // a regular SDL texture

    //Initialize the background with given path and renderer
    bool InitBackground(char* FILE, SDL_Renderer* Rend)
    {
        SDL_Surface* tempSurf = NULL; // surface
        SDL_Texture* tempTexture = NULL; // texture

        // loads the file in the surface
        if((tempSurf = IMG_Load(FILE)) == NULL)
        {
            printf( "Unable to load background %s! SDL_image Error: %s\n", FILE, IMG_GetError() );

            return false;
        }

        // loads the texture from the surface
        if( (tempTexture = SDL_CreateTextureFromSurface( Rend, tempSurf)) == NULL )
        {
            printf( "Unable to create background texture from %s! SDL Error: %s\n", FILE, SDL_GetError() );

            return false;
        }

        texture = tempTexture; // set the main texture

        SDL_FreeSurface(tempSurf); // free the surface memory

        return true;
    }

    //Render the background
    void render(SDL_Renderer* Rend)
    {
        if(texture == NULL)
        {
            printf("There is no texture to render\n");
        }

        if(Rend == NULL)
        {
            printf("Invalid renderer\n");
        }

        SDL_RenderCopyEx( Rend, texture, NULL, NULL, 0, NULL, SDL_FLIP_NONE );
    }
};

#endif // BACKGROUND_H_INCLUDED
