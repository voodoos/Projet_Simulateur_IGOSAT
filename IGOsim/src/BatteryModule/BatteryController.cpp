#include "BatteryController.h"

using namespace std;


BatteryController::BatteryController(Params params) : Module("Battery Controller", params){
    //Les messages compris par le controlleur:
    addMessage(Message("getStatus", "nothing", 5), 5);
    addMessage(Message("actualVoltage", "nothing", 5), 5);

    //Les connecteurs:
    addSocket(Socket("toBattery"));
    addSocket(Socket("toExt"));
}

void BatteryController::process(Message m){
    if (m.getName() == "getStatus") {
        //On demande le voltage à la batterie et on attend sa réponse:
        getSocketByName("toBattery")->send(Message("getVoltage", "nothing", 5));
    }
    if (m.getName() == "actualVoltage") {
        //Reponse de la batterie:
        if (atoi(m.getPayload().c_str()) > 10) {
            //Si voltage suffisant:
            CLI::getInstance().log(CLI::INFO, "Status OK");
        }
        else {
            CLI::getInstance().log(CLI::INFO, "Status KO: Insufficient voltage");
        }
    }
}