#include "Game.h"

bool Game::LoadContent()
{
    User.Character.init(Renderer, "./Resources/Textures/character.png", 0, 0);
    User2.Character.init(Renderer, "./Resources/Textures/character.png", 0, 0);

    return true;
}
