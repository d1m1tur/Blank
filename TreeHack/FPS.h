#ifndef SDL_FPS_H_INCLUDED
#define SDL_FPS_H_INCLUDED

    int tick;

    void CapFrameRate(int FPS)
    {
        tick = SDL_GetTicks();
        if((1000/FPS) > (SDL_GetTicks() - tick))
        {
            SDL_Delay(1000/FPS);
        }
    }

#endif // SDL_FPS_H_INCLUDED
