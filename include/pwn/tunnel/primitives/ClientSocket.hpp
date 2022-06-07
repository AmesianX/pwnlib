/*
        Copyright (C) 2022 Heewon Cho
        ClientSocket.hpp
*/

#ifndef _CLIENTSOCKET_HPP
#define _CLIENTSOCKET_HPP

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

#include <pwn/utils/Dye.hpp>
#include <pwn/tunnel/primitives/Pipe.hpp>

class ClientSocket : public Pipe {
    private:

    public:
        ClientSocket();
        ~ClientSocket();

        void Connect(std::string addr, unsigned short port);

};

#endif