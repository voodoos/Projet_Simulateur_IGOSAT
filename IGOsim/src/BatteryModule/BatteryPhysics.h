#pragma once
#include "Physics.h"

#include <memory>

class Battery;
class BatteryPhysics :
    public Physics
{
public:
    BatteryPhysics(std::shared_ptr<Module>);
    virtual ~BatteryPhysics();

    void clock(int t);
};

