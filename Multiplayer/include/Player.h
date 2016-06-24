#ifndef PLAYER_H
#define PLAYER_H

#include "LGTexture.h"

class Player
{
    public:
        Player();
        virtual ~Player();

        void init(SDL_Renderer* Rend, char* FILE, int x_, int y_);
        void render(SDL_Renderer* Rend);
        void movement(int x_, int y_);

        void setCoord(int x_, int y_);

        int xPos;
        int yPos;

    protected:

    private:

        LGTexture image;


};

#endif // PLAYER_H
