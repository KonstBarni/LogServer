#pragma once
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 6655
#define MESSAGE_LENGTH 1024

class ServTCP
{
public:
    struct sockaddr_in serveraddres, client;
    socklen_t length;
    int socket_file_descriptor, connection, bind_status, connection_status;
    char sv_mess[1024];
    void createSocket();
    void bindSocket();
    void closeSocket();
    void dataReceivingServer();
    char* readData();
    void writeData(std::string servMess);


};