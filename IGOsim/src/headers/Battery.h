#pragma once
#include <iostream>
#include "Module.h"


class Battery: public Module{
private:
    void process(Message);
public:
    Battery(Params = Params());
};