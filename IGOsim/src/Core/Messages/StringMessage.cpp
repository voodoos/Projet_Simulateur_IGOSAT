
#include "StringMessage.h"

StringMessage::StringMessage(std::string name, std::string payload, int time):Message(name, time), payload(payload)
{
}

std::string StringMessage::getPayload(){
    return payload;
}

std::ostream& StringMessage::operator<<(std::ostream &os){
    os << payload;
    return os;
}