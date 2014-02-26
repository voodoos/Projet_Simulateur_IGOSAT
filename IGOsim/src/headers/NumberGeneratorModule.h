#pragma once

#include <iostream>
#include "Module.h"
#include "Socket.h"
#include "Message.h"

class NumberGeneratorModule:public Module{
public:
    NumberGeneratorModule();
    void start();
    Socket *getOutSocket();
};