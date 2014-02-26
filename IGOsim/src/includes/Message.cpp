#include "Message.h"


Message::Message(std::string name, std::string payload)
{
    this->name = name;
    this->payload = payload;
}


Message::~Message()
{
}

std::string Message::getPayload(){
    return this->payload;
}
