#include "Game.h"

Entity::Entity()
{
    Image = NULL;

    draggable = false;
    enabled = false;
}

Entity::~Entity()
{
    //dtor
}

void Entity::CreateEntity(float x, float y, float w, float h)
{
    //Checking the image
    if(Image == NULL)
    {
        cout<<"An entity is without an Image"<<endl;
    }

    //Setting coordinates
    XPos = x;
    YPos = y;
    Width = w;
    Height = h;

    defaultX = XPos;
    defaultY = YPos;
    defaultW = Width;
    defaultH = Height;
}

bool Entity::CheckColl(float Bx, float By, float Bw, float Bh)
{

    if ( YPos + Height < By ) return false;
    else if ( YPos > By + Bh ) return false;
    else if ( XPos + Width < Bx ) return false;
    else if ( XPos > Bx + Bw ) return false;

    return true;
}

bool Entity::CheckEntityColl(Entity object)
{
    float Bx = object.XPos;
    float By = object.YPos;
    float Bw = object.Width;
    float Bh = object.Height;

    /*if ( YPos + Height < By ) return false;
    else if ( YPos > By + Bh ) return false;
    else if ( XPos + Width < Bx ) return false;
    else if ( XPos > Bx + Bw ) return false;*/

    if(!CheckColl(Bx, By, Bw, Bh)) return false;

    return true;
}

bool Entity::Hover(float Mx, float My)
{
    if( YPos + Height < My) return false;
    else if( YPos > My) return false;
    else if( XPos + Width < Mx) return false;
    else if( XPos > Mx) return false;

    return true;
}

void Entity::Responsive(float Kx, float Ky)
{
    XPos = defaultX * Kx;
    YPos = defaultY * Ky;
    Width = defaultW * Kx;
    Height = defaultH * Ky;
}
