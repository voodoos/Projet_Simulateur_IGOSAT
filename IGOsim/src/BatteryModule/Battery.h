#pragma once
#include <iostream>
#include "Module.h"


class Battery: public Module{
private:
    void process(std::shared_ptr<Message>);
public:
    Battery(Params = Params());
};