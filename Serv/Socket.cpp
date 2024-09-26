#include "Socket.h"
#include <filesystem>

//namespace fs = filesystem;

void ServTCP::createSocket()
{
    socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);

    if(socket_file_descriptor == -1){
        std::cout << "Creation of sock failed" << std::endl;
        exit(1);
    }
    else{
        std::cout << "Sock created" << std::endl;
    }
}

void ServTCP::bindSocket()
{
    serveraddres.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddres.sin_port = htons(PORT);
    serveraddres.sin_family = AF_INET;
    bind_status = bind(socket_file_descriptor, (struct sockaddr*)&serveraddres, sizeof(serveraddres));
    if (bind_status == -1) {
        std::cout << "Socket binding failed.!" << std::endl;
        exit(1);
    }
    else {
        std::cout << "The socket binding was successful!" << std::endl;
    }
}

void ServTCP::closeSocket()
{
    close(socket_file_descriptor);
}

void ServTCP::dataReceivingServer()
{
    connection_status = listen(socket_file_descriptor, 5);

    if (connection_status == -1) {
        std::cout << "Socket is unable to listen for new connections!" << std::endl;
        exit(1);
    }
    else {
        std::cout << "Server is listening for new connection: " << std::endl;
    }

    length = sizeof(client);
    connection = accept(socket_file_descriptor, (struct sockaddr*)&client, &length);

    if (connection == -1) {
        std::cout << "Server is unable to accept the data from client!" << std::endl;
        exit(1);
    }
    else {
        std::cout << "The client has joined!" << std::endl;
    }
}

char* ServTCP::readData()
{
    bzero(sv_mess, MESSAGE_LENGTH);
    read(connection, sv_mess, sizeof(sv_mess));
    std::cout << "Data received from client: " << sv_mess << std::endl;
    return sv_mess;
}

void ServTCP::writeData(std::string serverMessage)
{
    bzero(sv_mess, MESSAGE_LENGTH);
    ssize_t bytes = write(connection, strcpy(sv_mess, serverMessage.c_str()), sizeof(sv_mess));

    if (bytes >= 0) {
        std::cout << "Data successfully sent to the client!" << sv_mess << std::endl;
    }
}

