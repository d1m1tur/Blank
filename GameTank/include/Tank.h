#ifndef TANK_H
#define TANK_H
#include "SDL.h"
#include "SDL_image.h"
#include<iostream>

class Tank
{
    private:
        SDL_Rect tankSprite;
        SDL_Rect tankPos;
        float frameCounter;
        int direction;
        float moveSpeed = 100.0f;
        SDL_Scancode key[4];
        int tankNum;
        SDL_Texture* tempT;
    public:
        SDL_Texture* tankTextureRight;
        void setTextureRight (std::string, SDL_Renderer*);
        SDL_Texture* tankTextureLeft;
        void setTextureLeft (std::string, SDL_Renderer*);
        SDL_Texture* tankTextureDown;
        void setTextureDown (std::string, SDL_Renderer*);
        SDL_Texture* tankTextureUp;
        void setTextureUp (std::string, SDL_Renderer*);
        //void setSprite(SDL_Rect);
        //void setPos(SDL_Rect);
        void setDirection(int);
        int getD();
        float getSpeed();
        SDL_Rect getPos();
        SDL_Rect getSprite();
        void setPosx(float);
        void setPosy(float);
        void setSpritey(float);
        void setSpritex(float);
        Tank(int);
        virtual ~Tank();
        void tankMove(const Uint8*, float);
        void draw(SDL_Renderer*);
        bool interesectsWith(Tank t);

        void setSpeed(float sp)
        {
            moveSpeed = sp;
        }

    protected:


};

#endif // TANK_H
