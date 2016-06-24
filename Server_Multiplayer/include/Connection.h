#ifndef CONNECTION_H
#define CONNECTION_H

#include <SDL_net.h>
#include <iostream>
#include <vector>

class Connection
{
    public:
        Connection();
        virtual ~Connection();

        int Execute();
        bool running;

    protected:

    private:

        class Client
        {

            public:
                Client();
                Client(const Client &other);
                virtual ~Client();

                void Connect(int ID_, Uint32 h_, Uint16 p_, int ch_);
                void Disconnect();


                int ID;
                Uint32 host_;
                Uint16 port_;
                int channel_;
                Uint8* data_;

                bool matched;
                Uint32 match_host;
                static int clientsLooking;

                bool connected;
                static int clientsNum;
                static int set_id;

                static std::vector<Client*> clients;

                static Client* getClient_ID(int ID_);
                static Client* getClient_host(Uint32 host_);
                static void showClients();
                static Client* getMatch();
        };

        static const int MAX_CLIENTS = 10;

        Client clients_array[MAX_CLIENTS];

        IPaddress ip;

        UDPsocket sock;
        UDPpacket *input;
        UDPpacket *output;

        bool Init();
        void addClient();
        void MatchClients();
        void Receive();
        void Resend();
        void Exit();
};

#endif // CONNECTION_H
