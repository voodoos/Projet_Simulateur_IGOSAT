#pragma once
#include <iostream>

#include "Module.h"

class BatteryController:public Module{
public:
    BatteryController(Params = Params());
private:
    void process(std::shared_ptr<Message>);
};