#pragma once
#include <iostream>

#include "Module.h"
#include "CLI.h"

class BatteryController:public Module{
public:
    BatteryController(Params = Params());
private:
    void process(Message *m);
};