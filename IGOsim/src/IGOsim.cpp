// IGOsim.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include "CLI.h"
#include "Battery.h"
#include "BatteryController.h"
#include "BatteryModule.h"
#include "BatteryPhysics.h"
#include "HCI.h"
#include "Module.h"
#include "MacroModule.h"
#include "Socket.h"
#include "Timer.h"

//For convenience:
using namespace std;


int main()
{
    cout << "Hello space!" << endl;;
    

    /* Exemple de batterie: */
    BatteryModule *bm = new BatteryModule("BModule");

    bm->getSocketByName("fromExt")->send(Message("getStatus", "nothing", 5));
    bm->getSocketByName("fromExt")->send(Message("getStatus", "nothing", 5));
    bm->getSocketByName("fromExt")->send(Message("getStatus", "nothing", 10));

    Timer::getInstance().addModule(bm);



    Timer::getInstance().start(100);

    delete(bm);

    /*
    unordered_map<string, double> p;

    p["voltage"] = 12;
    p["amperage"] = 0.2;
    p["capacity"] = 10000;
    p["TEMP1"] = 30;
    p["TEMP2"] = 35;
    p["TEMP3"] = 40;
    p["TEMP4"] = 45;

    Battery b = Battery("Battery1", p);
    b.addMessage(Message("showVoltage", "nothing", 5), 5);
    b.addMessage(Message("showAmperage", "nothing", 5), 5);
    b.addMessage(Message("showCapacity", "nothing", 5), 5);
    b.addMessage(Message("getTemp1", "nothing", 5), 5);
    b.addMessage(Message("getTemp2", "nothing", 5), 5);
    b.addMessage(Message("getTemp3", "nothing", 5), 5);
    b.addMessage(Message("getTemp4", "nothing", 5), 5);
    
    b.addSocket(Socket("bSocket"));
    
    Timer::getInstance().addModule(&b);


    BatteryPhysics bp = BatteryPhysics(&b);

    Timer::getInstance().addPhysics(&bp);
    
    /* Exemple de batterie controlleur: 

    unordered_map<string, double> pbc;
    
    p["uptime"] = 4;
    p["charge"] = 100;
    
    BatteryController bc = BatteryController("BController", pbc);


    
    bc.addSocket(Socket("bcSocket"));
    
    Timer::getInstance().addModule(&bc);

    /* Exemple de batterie module: 

    unordered_map<string, double> pbm;
    
    BatteryModule bm = BatteryModule("BModule", pbm);
    
    bm.addSubModule(&b);
    bm.addSubModule(&bc);
    bm.addConnexion(Connexion(&b.getSocketByName("bSocket"), &bc.getSocketByName("bcSocket")));
    
    bc.getSocketByName("bcSocket").receive(Message("getStatus", "nothing", 5));
    bc.getSocketByName("bcSocket").receive(Message("getTemperatures", "nothing", 5));
    
    //For physic test:
    b.getSocketByName("bSocket").receive(Message("showVoltage", "nothing", 5));
    b.getSocketByName("bSocket").receive(Message("showVoltage", "nothing", 5));
    b.getSocketByName("bSocket").receive(Message("showVoltage", "nothing", 20));

    Timer::getInstance().start(100);
    */
    cin.ignore();

	return 0;
}


