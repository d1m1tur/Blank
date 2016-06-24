#include "Game.h" // include the game
#include "ServerConnection.h" // include the server connection

//Main function

int main(int argc, char ** argv)
{
    ServerConnection conn;

    Game Kagan;
    Kagan.Run("Gosho"); //Execute game with user name Gosho

    return 0;
}
