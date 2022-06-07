/*
        Copyright (C) 2022 Heewon Cho
        Pipe.hpp
*/

#ifndef _PIPE_HPP
#define _PIPE_HPP

#include <unistd.h>

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

#include <pwn/utils/Dye.hpp>

class Pipe {
    protected:
        int fd;
        
    public:

        void Send(std::vector<unsigned char> data);
        std::vector<unsigned char> Recv(int size);
};

#endif