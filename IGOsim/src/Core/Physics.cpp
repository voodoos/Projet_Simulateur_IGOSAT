
#include "Module.h"
#include "Physics.h"
#include "Timer.h"

Physics::Physics(Module *m) : module(m)
{
    Timer::getInstance().add(this);
}


Physics::~Physics()
{
}
