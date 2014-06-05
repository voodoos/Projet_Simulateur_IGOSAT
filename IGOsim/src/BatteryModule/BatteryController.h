#pragma once
#include <iostream>

#include "Module.h"
#include "HCI.h"
#include "HCIs.h"

class BatteryController:public Module{
public:
    BatteryController(Params = Params());
private:
    void process(std::shared_ptr<Message>);
};