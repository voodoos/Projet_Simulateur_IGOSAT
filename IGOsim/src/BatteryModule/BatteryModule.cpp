#include "BatteryModule.h"

using namespace std;

BatteryModule::BatteryModule(std::string name, Params params) : MacroModule(name, params){

    //Paramètres:
    unordered_map<string, double> p;

    p["voltage"] = 40;
    p["amperage"] = 0.2;
    p["capacity"] = 10000;
    p["TEMP1"] = 30;
    p["TEMP2"] = 35;
    p["TEMP3"] = 40;
    p["TEMP4"] = 45;


    //Les modules:
    battery = new Battery(p);
    batteryController = new BatteryController(Params());

    //La physique:
    batteryPhysics = new BatteryPhysics(battery);


    //Les messages compris par le macromodule batterie:
    addMessage(StringMessage("getStatus", "nothing", 5), 5);

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