#include "Message.h"


Message::Message(std::string name, std::string payload, int pt) : name(name), payload(payload), transmissionTime(pt)
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

int Message::getTransmissionTime(){
    return transmissionTime;
}