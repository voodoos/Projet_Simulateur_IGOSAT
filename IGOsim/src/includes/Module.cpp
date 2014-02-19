#include "Module.h"
#include "Memory.cpp"


Module::Module()
{
}

Module::Module(Memory<int> mem)
{
    this->mem = mem;
}


Module::~Module()
{
}


void Module::addSocket(Socket soc)
{
    this->sockets.insert(this->sockets.end(), soc);
}

void Module::addMessage(Message msg)
{
    this->messages.insert(this->messages.end(), msg);
}
