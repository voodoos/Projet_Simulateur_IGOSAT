// IGOsim.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include "Battery.h"
#include "BatteryController.h"
#include "BatteryModule.h"
#include "BatteryPhysics.h"
#include "Module.h"
#include "MacroModule.h"
#include "Socket.h"
#include "Timer.h"
#include "XMLReader.h"

<<<<<<< HEAD
#define SET_XMLPATH XMLReader::setPath("/Users/stagiaire/Documents/Projet_Simulateur_IGOSAT/IGOsim/config/");

#ifdef TARGET_OS_X
    #define SET_XMLPATH XMLReader::setPath("/Users/stagiaire/Documents/Projet_Simulateur_IGOSAT/IGOsim/config/");
#elif defined _WIN32 || defined _WIN64
    #define SET_XMLPATH  std::cout<<std::endl;
=======
//Output:
#include "HCI.h"
#include "HCIs.h"


#ifdef __APPLE__
    #define setXMLpath XMLReader::setPath("/Users/CoolerMaster/Dropbox/Etudes/ProjetLong/Projet_Simulateur_IGOSAT/IGOsim/config/");
#else
    #define setXMLpath  std::cout<<std::endl;
>>>>>>> master
#endif

//For convenience:
using namespace std;


int main(int argc, char *argv[])
{
    /* BASIC CONFIGURATION */
<<<<<<< HEAD
    //XMLReader::setPath(setXMLpath);
    SET_XMLPATH
    CLI::getInstance().setLogLevel(CLI::INFO);
=======
    //XMLReader::setPath("/Users/CoolerMaster/Dropbox/Etudes/ProjetLong/Projet_Simulateur_IGOSAT/IGOsim/config/");

    //On initialise les interfaces utilisateurs.
    HCIs::getInstance().setLog("test.log", HCI::INFO);
    HCIs::getInstance().addDataOutput("BV", "batterieVoltage.data");

    /*Le module de base, le Satellite */
    //Sate
    
>>>>>>> master

        /* Exemple batterie */ 
        BatteryModule *bm = new BatteryModule("BatteryModule");

        (*bm)["fromExt"]->send(Message::createMessage("getStatus", "nothing", 5));
        (*bm)["fromExt"]->send(Message::createMessage("getStatus", "nothing", 5));
        (*bm)["fromExt"]->send(Message::createMessage("getStatus", "nothing", 10));
        

        Timer::getInstance().start(100);

        //delete(bm);
        
        cin.ignore();

	return 0;
}

