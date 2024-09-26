#pragma once
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

using namespace std;

#define MESSAGE_LENGTH 1024
#define PORT 6655

class Client
{
    bool work;
    string mesToSend;
    
public:
    Client();
    int socket_file_descriptor, connection;
    struct sockaddr_in serveraddress, client;
    char message[MESSAGE_LENGTH];

    void createSocket();
    void connectionToServer();
    void closeSocket();
    char* readData();
    void writeData(string clientMessage);

};