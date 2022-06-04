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

class ClientSocket {
    private:
        int fd;

    public:
        ClientSocket();
        ~ClientSocket();

        void Connect(std::string addr, unsigned short port);

        void Send(std::vector<unsigned char> data);
        std::vector<unsigned char> Recv();

};

#endif