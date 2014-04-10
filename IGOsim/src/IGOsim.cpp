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
#include "XMLReader.h"

#ifdef __APPLE__
    #define setXMLpath XMLReader::setPath("/Users/CoolerMaster/Dropbox/Etudes/ProjetLong/Projet_Simulateur_IGOSAT/IGOsim/config/");
#elif
    #define setXMLpath  std::cout<<std::endl;
#endif

//For convenience:
using namespace std;


int main()
{
    setXMLpath
    CLI::getInstance().setLogLevel(CLI::INFO);
    
    /* Exemple de batterie: */
    BatteryModule *bm = new BatteryModule("BatteryModule");

    (*bm)["fromExt"]->send(Message::createMessage("getStatus", "nothing", 5));
    (*bm)["fromExt"]->send(Message::createMessage("getStatus", "nothing", 5));
    (*bm)["fromExt"]->send(Message::createMessage("getStatus", "nothing", 10));


    Timer::getInstance().start(100);

    delete(bm);

    cin.ignore();

	return 0;
}

