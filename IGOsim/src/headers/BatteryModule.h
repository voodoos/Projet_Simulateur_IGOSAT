#pragma once
#include <iostream>

#include "MacroModule.h"
class BatteryModule:public MacroModule{
public:
    BatteryModule(std::string name, Params params);
private:
    virtual void process(Message);
};