#include <iostream>
#include <string.h>
#include <chrono>
#include <thread>
#include "ClientTCP.h"

int main()
{
    std::string messToSend = "Client is working";
    int stop{0};
    Client client;
    client.createSocket();
	client.connectionToServer();

    std::cout << "Input time ";
    std::cin >> stop;

    client.writeData(messToSend);

    while (stop != 0)
    {
 //       client.writeData(messToSend);
 //       std::cout << messToSend << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        stop--;
    }
    messToSend = "end";
    client.writeData(messToSend);
    client.closeSocket();


    return 0;
}