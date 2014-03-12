#include "BatteryPhysics.h"


BatteryPhysics::BatteryPhysics(Battery *m) : Physics(m)
{
}


BatteryPhysics::~BatteryPhysics()
{
}


void BatteryPhysics::clock(int t){
    module->setParamValueByName("voltage", module->getParamValueByName("voltage")-1);
}