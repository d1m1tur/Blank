#include "Characters.h"

Characters::Characters()
{
    CanMove = true;
}

Characters::~Characters()
{
    //dtor
}

void Characters::MoveLeft()
{
    if(CanMove == true)
    {
        XPos -= 10;
        Flip = SDL_FLIP_HORIZONTAL;
    }
}

void Characters::MoveRight()
{
    if(CanMove == true)
    {
        XPos += 10;
        Flip = SDL_FLIP_NONE;
    }
}

bool Characters::Gravity(int WindowHeight)
{
    if(YPos + Height >= WindowHeight - 50)
    {
        return false;
    }

    YPos += 10;
    return true;
}
