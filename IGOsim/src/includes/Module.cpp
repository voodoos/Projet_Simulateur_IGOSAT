#include "Module.h"
#include "Memory.cpp"


Module::Module()
{
}

Module::Module(Memory<int> mem)
{
    this->memory = mem;
}


Module::~Module()
{
    
}

Socket *Module::socketWithName(std::string sname)
{
    std::vector<Socket>::iterator it;
    for(it = this->sockets.begin(); it != this->sockets.end(); ++it) {
        if (sname == it->getName()) {
            return &(*it);
        }
    }
    return NULL;
}


void Module::addSocket(Socket soc)
{
    this->sockets.insert(this->sockets.end(), soc);
}

void Module::addMessage(Message msg)
{
    this->messages.insert(this->messages.end(), msg);
}
