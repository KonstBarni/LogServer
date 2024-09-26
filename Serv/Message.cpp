#include "Message.h"

Message::Message(std::string& mess)
{
    this->message = mess;
}

void Message::print()
{
    std::cout << this->message << std::endl;
}