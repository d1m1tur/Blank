#include "Connection.h"

int Connection::Client::clientsNum = 0;
int Connection::Client::clientsLooking = 0;
int Connection::Client::set_id = 0;
std::vector<Connection::Client*> Connection::Client::clients;

Connection::Connection()
{
    running = true;
}

Connection::~Connection()
{
    //dtor
}

void Connection::Client::Connect(int ID_, Uint32 h_, Uint16 p_, int ch_)
{
    host_ = h_;
    port_ = p_;
    channel_ = ch_;

    matched = false;
    match_host = 0;
    clientsLooking ++;

    connected = true;
    clientsNum++;

    clients.push_back(this);
}

void Connection::Client::Disconnect()
{
    host_ = 0;
    port_ = 0;
    channel_ = 0;

    if(matched == false)
        clientsLooking--;

    matched = false;
    match_host = 0;

    connected = false;
    clientsNum--;

    clients.erase(clients.begin() + ID);
}


Connection::Client::Client()
{
    ID = set_id;
    set_id++;
}

Connection::Client::~Client()
{

}

Connection::Client::Client(const Connection::Client &other)
{
    data_ = new Uint8;
    *data_ = *other.data_;

    ID = other.ID;
    host_ = other.host_;
    port_ = other.port_;
    channel_ = other.channel_;

    connected = other.connected;
}

Connection::Client* Connection::Client::getClient_ID(int ID_)
{
    for(std::vector<Client*>::iterator it = clients.begin(); it != clients.end(); it++)
    {
        if((*it)->ID == ID_)
            return *it;
    }

    return NULL;
}

Connection::Client* Connection::Client::getClient_host(Uint32 host_)
{
    for(std::vector<Client*>::iterator it = clients.begin(); it != clients.end(); it++)
    {
        if((*it)->host_ == host_)
            return *it;
    }

    return NULL;
}

void Connection::Client::showClients()
{
    for(std::vector<Client*>::iterator it = clients.begin(); it != clients.end(); it++)
    {
        std::cout << "Host: "<< (*it)->host_<< "    ID: "<< (*it)->ID << std::endl;
    }
}

Connection::Client* Connection::Client::getMatch()
{
    for(std::vector<Client*>::iterator it = clients.begin(); it != clients.end(); it++)
    {
        if((*it)->matched == false)
            return *it;
    }
}

int Connection::Execute()
{
    if(!Init()) return 1;

    while(running)
    {
        Receive();
    }

    Exit();

    return 0;
}

int main(int argc, char* argv[])
{
    Connection server;

    return server.Execute();
}

