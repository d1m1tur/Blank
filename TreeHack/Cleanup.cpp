#include "Game.h"

void Game::Cleanup()
{
    data.open("D:\database.hack");

    data << water << "\n";
    data << fertilize;

    data.close();

    ///Free memory

    //Mixer

    Mix_FreeChunk( rain_drop1 );
    Mix_FreeChunk( rain_drop2 );
    Mix_FreeChunk( throw_trash1 );
    Mix_FreeChunk( throw_trash2 );

    Mix_FreeMusic( wind );

    Mix_CloseAudio();

    SDL_FreeCursor(Cursor);
    SDL_FreeCursor(DragCursor);

    //SDL
    SDL_DestroyTexture(MySun.Animate);
    SDL_DestroyTexture(Sun.Image);
    SDL_DestroyTexture(MyMoon.Animate);
    SDL_DestroyTexture(Moon.Image);
    SDL_DestroyTexture(Block.Image);
    SDL_DestroyTexture(backDay);
    SDL_DestroyTexture(backNight);
    SDL_DestroyTexture(Background);
    SDL_DestroyTexture(Block.Image);
    SDL_DestroyTexture(R1);
    SDL_DestroyTexture(R2);
    SDL_DestroyTexture(R3);
    SDL_DestroyTexture(R4);
    SDL_DestroyTexture(R5);
    SDL_DestroyTexture(R6);
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_FreeSurface(Icon);
    SDL_Quit();
}
