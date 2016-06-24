#include "Game.h"
#include <stdlib.h>     /* atoi */

using namespace std;

void Game::Loop()
{
    string enemyCoord;
    enemyCoord = User.Receive();

    if(enemyCoord != "false" )
    {
        if(User2.online == false)
            User2.online = true;

        size_t pos = enemyCoord.find_first_of(" ");
        size_t length = enemyCoord.length() - pos;

        char first[pos];
        char second[length];

        enemyCoord.copy(first, length, pos + 1);
        enemyCoord.copy(second, pos, 0);

        string text_y = first;
        string text_x = second;

        int y = atoi(text_y.c_str());
        int x = atoi(text_x.c_str());

        User2.Character.setCoord(x, y);
    }

}
