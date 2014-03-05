#include "NumberGeneratorModule.h"


NumberGeneratorModule::NumberGeneratorModule()
{
    this->name = "Generator";
    this->addSocket(Socket("Generator Output"));
}

void NumberGeneratorModule::start()
{
    int value;
    for(int i = 0; i < 10; ++i){
        value = rand()%1000;
        Message m("hello", std::to_string(value));
        this->sockets[0].send(m);
    }
}


Socket *NumberGeneratorModule::getOutSocket(){
    return &this->sockets[0];
}