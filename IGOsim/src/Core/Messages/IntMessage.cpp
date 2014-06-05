
#include "IntMessage.h"

IntMessage::IntMessage(std::string name, int payload, int time):Message(name, time), payload(payload)
{
}

int IntMessage::getPayload(){
    return payload;
}

std::ostream& IntMessage::operator<<(std::ostream &os){
    os << payload;
    return os;
}
