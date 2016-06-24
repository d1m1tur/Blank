#include "Connection.h"

bool Connection::Init()
{
    if(SDLNet_Init() > 0)
    {
        std::cerr << "Failed to initialize SDLNet "<< SDLNet_GetError() << std::endl;
        return false;
    }

    IPaddress ip;

    sock = SDLNet_UDP_Open(1234);

    input = SDLNet_AllocPacket(1024);
    output = SDLNet_AllocPacket(1024);

    return true;
}

void Connection::Receive()
{
    if(Client::clientsLooking >= 2)
        MatchClients();

    if (SDLNet_UDP_Recv(sock, input))
    {
        std::string query = (char*)input->data;

        if(Client::getClient_host(input->address.host) != NULL)
        {
            if(query == "Disconnect")
            {
                std::cout << "A client has disconnected" <<std::endl;
                Client::getClient_host(input->address.host)->Disconnect();
            }
            else
            {
                Client::getClient_host(input->address.host)->data_ = input->data;
                std::cout <<"Client with host " <<input->address.host<<std::endl;
                std::cout <<"Client with port " <<input->address.port<<std::endl;
                std::cout <<"Client with channel " <<input->channel<<std::endl<<std::endl;

                if(Client::getClient_host(input->address.host)->matched)
                {
                    Uint32 send_host = Client::getClient_host(input->address.host)->match_host;

                    std::cout <<"Send to host " <<send_host<<std::endl;
                    std::cout <<"Send to port " <<Client::getClient_host(send_host)->port_<<std::endl;
                    std::cout <<"Send to channel " <<Client::getClient_host(send_host)->channel_<<std::endl<<std::endl;

                    output->address.host = send_host;
                    output->address.port = Client::getClient_host(send_host)->port_;
                    output->channel  = Client::getClient_host(send_host)->channel_;
                    output->data = input->data;
                    output->len = input->len;

                    SDLNet_UDP_Send(sock, output->channel, output);
                }
            }
        }
        else
        {
            if(query == "Login")
                addClient();
        }
    }
}

void Connection::addClient()
{
    if(Client::clientsNum < MAX_CLIENTS)
    {
        int ID = 0;

        for(int i = 0; i < 10; i++)
        {
            if(clients_array[i].connected == false)
            {
                ID = clients_array[i].ID;
                break;
            }
        }

        std::cout << ID << "   New client online" <<std::endl;
        clients_array[ID].Connect(ID, input->address.host, input->address.port, input->channel);
        Client::showClients();
    }
    else
    {
        std::cout << "Server is FULL" <<std::endl;
    }
}

void Connection::MatchClients()
{
    Client* first;
    Client* second;

    first = Client::getMatch();
    first->matched = true;

    second = Client::getMatch();
    second->matched = true;

    first->match_host = second->host_;
    second->match_host = first->host_;

    Client::clientsLooking -= 2;
}

void Connection::Exit()
{
    SDLNet_FreePacket(input);
    SDLNet_FreePacket(output);
    SDLNet_UDP_Close(sock);

    SDLNet_Quit();
}
