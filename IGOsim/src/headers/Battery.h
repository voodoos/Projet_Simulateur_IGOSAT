#pragma once
#include <iostream>
#include "Module.h"


class Battery: public Module{
private:
    void process(Message);
public:
    Battery(std::string = "DefaultName", Params = Params());
};