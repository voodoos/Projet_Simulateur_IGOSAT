#include "BatteryModule.h"

using namespace std;

BatteryModule::BatteryModule(std::string name, Params params) : MacroModule(name, params, "BatteryModule/BatteryModule.xml"){


    //Les modules:
    battery = new Battery();
    batteryController = new BatteryController();

    //La physique:
    batteryPhysics = new BatteryPhysics(battery);

    //Les connecteurs du macromodule:
    addSocket(Socket("fromExt"));

    //Les connexions internes:
    /*! \todo Surcharger [] pour getsocketbyname */
    addConnexion(battery->getSocketByName("toBatteryController"), batteryController->getSocketByName("toBattery"));
    addConnexion(getSocketByName("fromExt"), batteryController->getSocketByName("toExt"));
}

BatteryModule::~BatteryModule() {
    //On supprime tous les modules:
    delete(battery);
    delete(batteryController);
    delete(batteryPhysics);
}

void BatteryModule::process(shared_ptr<Message>){
}