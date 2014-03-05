#include "Message.h"


Message::Message(std::string name, std::string payload) : name(name), payload(payload)
{
}


Message::~Message()
{
}

std::string Message::getName(){
    return this->name;
}

std::string Message::getPayload(){
    return this->payload;
}
