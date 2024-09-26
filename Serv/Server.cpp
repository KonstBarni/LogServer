#include <iostream>
#include "Message.h"
#include "Socket.h"
#include "string"
#include "Log.h"

int main()
{
    std::string end = "end";
    int quit{0};
    char* pup;


    std::cout << "Server started";


    ServTCP serv;
    serv.createSocket();
    serv.bindSocket();
    serv.dataReceivingServer();

    Log lg;
    lg.showTime();

    while(true)
    {    
        pup = serv.readData();

        if(pup == end)
            break;

        std::cout<<pup<<std::endl;
    }

    
    std::cout << "Input the messagr: ";
    std::cin >> end;

    
    return 0;
}