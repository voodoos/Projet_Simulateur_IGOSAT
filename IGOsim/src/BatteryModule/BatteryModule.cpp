#include "BatteryModule.h"

using namespace std;

BatteryModule::BatteryModule(std::string name, Params params) : MacroModule(name, params, "BatteryModule/BatteryModule.xml"){


    //Les modules:
    addSubModule(new Battery());
    addSubModule(new BatteryController());
    addSubModule(new Magnetometre());

    //La physique:
    batteryPhysics = new BatteryPhysics(getModuleByName("Battery"));

    //Les connexions internes:
    /*! \todo Surcharger [] pour getsocketbyname */
    ;
    addConnexion(new Connexion(getModuleByName("Battery")->getSocketByName("toBatteryController"), getModuleByName("BatteryController")->getSocketByName("toBattery")));
    addConnexion(new Connexion(this->getSocketByName("fromExt"), getModuleByName("BatteryController")->getSocketByName("toExt")));
    addConnexion(new Connexion(this->getSocketByName("toMagnetometre"), getModuleByName("Magnetometre")->getSocketByName("toODB")));
    
}

BatteryModule::~BatteryModule() {
}

void BatteryModule::process(shared_ptr<Message>){
    
}