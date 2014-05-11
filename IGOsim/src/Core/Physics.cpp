#include "Module.h"
#include "Physics.h"
#include "Timer.h"

using namespace std;

Physics::Physics(shared_ptr<Module> m) : module(m)
{
    Timer::getInstance().add(this);
}


Physics::~Physics()
{
}
