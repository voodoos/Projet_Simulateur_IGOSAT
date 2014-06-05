#include "Message.h"
#include "IntMessage.h"
#include "StringMessage.h"
#include "FloatMessage.h"

Message::Message(std::string name, int pt) : name(name), transmissionTime(pt)
{
}

Message::~Message()
{
    //std::cout << "Message " << name << " est detruit" << std::endl;
}

std::string Message::getName(){
    return name;
}

unsigned int Message::getTransmissionTime(){
    return transmissionTime;
}


std::shared_ptr<Message> Message::createMessage(std::string name, int payload, unsigned int transmissionTime){
    return std::shared_ptr<Message>(new IntMessage(name, payload, transmissionTime));
}

std::shared_ptr<Message> Message::createMessage(std::string name,std::string payload, unsigned int transmissionTime){
    return std::shared_ptr<Message>(new StringMessage(name, payload, transmissionTime));
}

std::shared_ptr<Message> Message::createMessage(std::string name, float payload, unsigned transmissionTime){
    return std::shared_ptr<Message>(new FloatMessage(name, payload, transmissionTime));
}