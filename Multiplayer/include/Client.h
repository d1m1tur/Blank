#ifndef CLIENT_H
#define CLIENT_H

#include "SDL_net.h"
#include "Player.h"
#include "iostream"

class Client
{
    public:
        Client();
        ~Client();

        bool Connect(std::string address);
        bool CheckConnection();
        void Disconnect();
        void SendData();

        std::string Receive();

        bool online;

        Player Character;


    protected:
    private:

        IPaddress ip;
        int channel;

        UDPsocket sock;
        UDPpacket *out;
        UDPpacket *in;




};

#endif // CLIENT_H
