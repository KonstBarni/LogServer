#pragma once
#include <iostream>
#include <string>


class Message
{
private:
    std::string message;

public:

    Message();
    Message(std::string& mess);
    void print();

};