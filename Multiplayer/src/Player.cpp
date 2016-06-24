#include "Player.h"
#include "iostream"

Player::Player()
{
    //ctor
}

Player::~Player()
{
    //dtor
}

void Player::init(SDL_Renderer* Rend, char* FILE, int x_, int y_)
{
    image.load(Rend, FILE);

    xPos = x_;
    yPos = y_;
}

void Player::render(SDL_Renderer* Rend)
{
    image.render(Rend, xPos, yPos);
}

void Player::movement(int x_, int y_)
{
    xPos += x_;
    yPos += y_;
}

void Player::setCoord(int x_, int y_)
{
    xPos = x_;
    yPos = y_;
}
