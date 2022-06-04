/*
        Copyright (C) 2022 Heewon Cho
        ClientSocket.cpp
*/

#include <pwn/tunnel/primitives/ClientSocket.hpp>

ClientSocket::ClientSocket() {
    if ((this->fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        throw []() -> void {
            std::clog << "[" + dye(BOLDRED, "-") + "] " + "An error occurred while creating the socket" << std::endl;
            std::exit(EXIT_FAILURE);
        };
    }
}

ClientSocket::~ClientSocket() {
    if (close(this->fd) == -1) {
        std::clog << "[" + dye(BOLDYELLOW, "-") + "] " + "An error occurred while closing the socket" << std::endl;
    }
}

void ClientSocket::Connect(std::string host, unsigned short port) {
    std::clog << "[" + dye(BOLDBLACK, "~") + "] " + "Opening connection to port " << port << std::endl;

    hostent *hostinfo;
    if ((hostinfo = gethostbyname(host.c_str())) == NULL) {
        std::string errmsg;
        switch (h_errno) {
            case HOST_NOT_FOUND:
                    errmsg = "HOST_NOT_FOUND";
                break;
            case NO_ADDRESS:
                    errmsg = "NO_ADDRESS";
                break;
            case NO_RECOVERY:
                    errmsg = "NO_RECOVERY";
                break;
            case TRY_AGAIN:
                    errmsg = "TRY_AGAIN";
                break;
        }
        throw [&]() -> void {
            std::clog << "[" + dye(BOLDRED, "-") + "] " + "Could not resolve hostname: "<< "'" << host << "': " + errmsg << std::endl;
            std::exit(EXIT_FAILURE);
        };
    }
    
    sockaddr_in info;
    std::memset(&info, 0x00, sizeof(info));
    info = { AF_INET, sa_family_t{ inet_addr(hostinfo->h_name) }, htons(port) };
    if (connect(this->fd, (const sockaddr *)&info, sizeof(info)) == -1) {
        throw []() -> void {
            std::clog << "[" + dye(BOLDRED, "-") + "] " + "Could not open connection to host" << std::endl;
            std::exit(EXIT_FAILURE);
        };
    }
}