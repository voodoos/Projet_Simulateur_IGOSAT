#include "Message.h"


Message::Message(std::string name, std::string payload, int pt) : name(name), payload(payload), processingTime(pt)
{
}


Message::~Message()
{
}

std::string Message::getName(){
    return name;
}

std::string Message::getPayload(){
    return payload;
}

int Message::getProcessingTime(){
    return processingTime;
}