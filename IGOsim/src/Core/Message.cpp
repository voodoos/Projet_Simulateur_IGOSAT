#include "Message.h"


Message::Message(std::string name, int pt) : name(name), transmissionTime(pt)
{
}

Message::~Message()
{
}

std::string Message::getName(){
    return name;
}

unsigned int Message::getTransmissionTime(){
    return transmissionTime;
}

std::ostream& Message::operator<<(std::ostream &os){
    return os;
}