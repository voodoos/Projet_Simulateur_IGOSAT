
#include "FloatMessage.h"

FloatMessage::FloatMessage(std::string name, float payload, int time):Message(name, time), payload(payload)
{
}

float FloatMessage::getPayload(){
    return payload;
}

std::ostream& FloatMessage::operator<<(std::ostream &os){
    os << payload;
    return os;
}