#include "Message.h"


Message::Message(std::string name, std::string payload, int pt) : name(name), payload(payload), processingTime(pt)
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

int Message::getProcessingTime(){
    return this->processingTime;
}