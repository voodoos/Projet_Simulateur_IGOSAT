#pragma once
#include <iostream>

#include "Module.h"

class BatteryController:public Module{
public:
    BatteryController(std::string = "DefaultName", Params = Params());
private:
    void process(Message m);
};