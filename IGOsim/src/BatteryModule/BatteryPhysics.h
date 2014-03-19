#pragma once
#include "Physics.h"
#include "Battery.h"

class BatteryPhysics :
    public Physics
{
public:
    BatteryPhysics(Battery *);
    virtual ~BatteryPhysics();

    void clock(int t);
};

