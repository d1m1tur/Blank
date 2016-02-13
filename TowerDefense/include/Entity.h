#ifndef ENTITY_H
#define ENTITY_H

#include "Includes.h"

class Entity
{
    public:
        Entity();
        ~Entity();

        SDL_Texture* Image;
        SDL_RendererFlip Flip;

        float XPos;
        float YPos;
        float Width;
        float Height;

        float defaultX;
        float defaultY;
        float defaultW;
        float defaultH;

        bool enabled;

        bool draggable;

        void CreateEntity(float x, float y, float w, float h);
        bool CheckColl(float Bx, float By, float Bw, float Bh);
        bool CheckEntityColl(Entity object);
        bool Hover(float Mx, float My);
        void Responsive(float Kx, float Ky);

    private:

};

#endif // ENTITY_H
