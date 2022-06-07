/*
        Copyright (C) 2022 Heewon Cho
        Pipe.cpp
*/

#include <pwn/tunnel/primitives/Pipe.hpp>

void Pipe::Send(std::vector<unsigned char> data) {
    if (write(this->fd, data.data(), data.size()) == -1) {
        std::string errmsg;
        switch (errno) {
            case EAGAIN:
                errmsg = "EAGAIN";
                break;
            case EBADF:
                errmsg = "EBADF";
                break;
            case EDESTADDRREQ:
                errmsg = "EDESTADDRREQ";
                break;
            case EDQUOT:
                errmsg = "EDQUOT";
                break;
            case EFAULT:
                errmsg = "EFAULT";
                break;
            case EFBIG:
                errmsg = "EFBIG";
                break;
            case EINTR:
                errmsg = "EINTR";
                break;
            case EINVAL:
                errmsg = "EINVAL";
                break;
            case EIO:
                errmsg = "EIO";
                break;
            case ENOSPC:
                errmsg = "ENOSPC";
                break;
            case EPERM:
                errmsg = "EPERM";
                break;
            case EPIPE:
                errmsg = "EPIPE";
                break;
            default:
                errmsg = "UNKNOWN";
                break;          
        }
        std::clog << "[" + dye(BOLDRED, "-") + "] " + "Error occured while writing data to descriptor: " + errmsg << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

std::vector<unsigned char> Pipe::Recv(int size) {
    static unsigned char buf[1024];
    if (read(this->fd, buf, size) == -1) {
        std::string errmsg;
        switch (errno) {
            case EAGAIN:
                errmsg = "EAGAIN";
                break;
            case EBADF:
                errmsg = "EBADF";
                break;
            case EFAULT:
                errmsg = "EFAULT";
                break;
            case EINTR:
                errmsg = "EINTR";
                break;
            case EINVAL:
                errmsg = "EINVAL";
                break;
            case EIO:
                errmsg = "EIO";
                break;
            case EISDIR:
                errmsg = "EISDIR";
                break;
            default:
                errmsg = "UNKNOWN";
                break;
        }
        std::clog << "[" + dye(BOLDRED, "-") + "] " + "Error occured while reading data from descriptor: " + errmsg << std::endl;
        std::exit(EXIT_FAILURE);
    }
}