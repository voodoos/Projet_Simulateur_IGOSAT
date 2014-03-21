#pragma once
#include <iostream>

#include "Battery.h"
#include "BatteryController.h"
#include "BatteryPhysics.h"
#include "MacroModule.h"

/*!
* \class BatteryModule
* \brief Un exemple de batterie
*
* On considère la batterie constituée de deux composants: la batterie en elle même, et son controlleur.
* Ceci est donc le macromodule qui les réunit.
*/

class BatteryModule:public MacroModule{
private:
    /*! \todo UNIQUE_PTR POINTER reset(new toto) */
    Battery *battery;
    BatteryController *batteryController;
    BatteryPhysics *batteryPhysics;

public:
    BatteryModule(std::string name, Params params = Params());
    virtual ~BatteryModule();

private:
    virtual void process(Message*);
};