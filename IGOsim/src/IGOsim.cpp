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

//For convenience:
using namespace std;


int main(int argc, char *argv[])
{
    /* BASIC CONFIGURATION */
    //XMLReader::setPath("/Users/CoolerMaster/Dropbox/Etudes/ProjetLong/Projet_Simulateur_IGOSAT/IGOsim/config/");
    CLI::getInstance().setLogLevel(CLI::INFO);
    
    //On analyse la ligne de commande:
    /* 
    *  Mode:
    *  0: normal
    *  1: generateur de module (-g)
    */
    int mode = 0; 

    while ((argc > 1) && (argv[1][0] == '-'))
    {
        switch (argv[1][1])
        {
            case 'g':
                mode = 1;
                break;
        }

        ++argv;
        --argc;
    }

    if (mode == 1) {
        //A déplacer ailleurs plus tard:
        bool isMacro = false;
        string isMacros = "";
        string nomModule = "";

        cout << "**GENERATION DE MODULE**" << endl;
        cout << "Macromodule ? (O/n)" << endl;
        cin >> isMacro;
        if (isMacros == "O") isMacro = true;
        
        cout << "Nom du module: ";
        cin >> nomModule;
    }
    else {
        /* Exemple de batterie: */
        /*BatteryModule *bm = new BatteryModule("BatteryModule");

        (*bm)["fromExt"]->send(Message::createMessage("getStatus", "nothing", 5));
        (*bm)["fromExt"]->send(Message::createMessage("getStatus", "nothing", 5));
        (*bm)["fromExt"]->send(Message::createMessage("getStatus", "nothing", 10));


        Timer::getInstance().start(100);

        delete(bm);
        */
        cin.ignore();
    }

	return 0;
}

