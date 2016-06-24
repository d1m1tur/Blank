#include "Client.h"
#include "sstream"

Client::Client()
{
    online = false;

    if ( SDLNet_Init() == -1 )
    {
        std::cerr << "SDLNet_Init failed : " << SDLNet_GetError() << std::endl;
    }
}

Client::~Client()
{
    online = false;

    SDLNet_FreePacket(out);
    SDLNet_FreePacket(in);
    SDLNet_UDP_Close(sock);
    SDLNet_Quit();
}

bool Client::Connect(std::string address)
{
    if(SDLNet_ResolveHost(&ip, address.c_str(), 1234) == -1)
    {
        std::cerr << "SDLNet_ResolveHost: " << SDLNet_GetError() << std::endl;
        return false;
    }

    sock = SDLNet_UDP_Open(0);
    out = SDLNet_AllocPacket(1024);
    in = SDLNet_AllocPacket(1024);

    channel = SDLNet_UDP_Bind(sock, -1, &ip);

    if(channel  == -1)
    {
        std::cerr << "SDLNet_UDP_Bind: " << SDLNet_GetError() << std::endl;
        return false;
    }

    online = Client::CheckConnection();

    return online;
}

bool Client::CheckConnection()
{
    Uint32 connecting = SDL_GetTicks();
    char query[] = "Login";

    out->data = (Uint8*)&query;
    out->len = sizeof(query);

    SDLNet_UDP_Send(sock, 0, out);

    /*while(true)
    {
        if(SDLNet_UDP_Recv(sock, in))
        {
            std::string Return = (char*)in->data;

            if(Return == "true")
                return true;
            else if(Return == "false")
                return false;
        }

        if(5000 < SDL_GetTicks() - connecting)
        {
            std::cout << "Connection timed out" << std::endl;
            return false;
        }
    }*/

    return true;
}

void Client::SendData()
{
    std::string Result; // string for result
    std::ostringstream convert; // stream for parsing

    convert << Character.xPos; // input the xpos
    convert << " "; // a whitespace
    convert << Character.yPos; // input the ypos

    Result = convert.str(); // convert to string

    char send[100]; // char array to send
    int size_res = Result.size(); // size
    int i = 0; // counter

    //get the string into the char array
    for(i = 0; i < size_res; i ++)
    {
        send[i] = Result[i];
    }
    send[i] = '\0'; // terminate


    //and send
    out->data = (Uint8*)&send;
    out->len = sizeof(send);

    SDLNet_UDP_Send(sock, 0, out);
}

std::string Client::Receive()
{
    if (SDLNet_UDP_Recv(sock, in))
    {
        std::string received = (char*)in->data;
        std::cout << received << std::endl;
        return received;
    }

    return "false";
}

void Client::Disconnect()
{
    char query[] = "Disconnect";

    out->data = (Uint8*)&query;
    out->len = sizeof(query);

    SDLNet_UDP_Send(sock, 0, out);

    std::cout << "Disconnecting" <<std::endl;
    SDL_Delay(1000);
}

