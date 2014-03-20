#include "BatteryController.h"

using namespace std;


BatteryController::BatteryController(Params params) : Module("Battery Controller", params){
    //Les messages compris par le controlleur:
    addMessage(StringMessage("getStatus", "nothing", 5), 5);
    addMessage(StringMessage("actualVoltage", "nothing", 5), 5);

    //Les connecteurs:
    addSocket(Socket("toBattery"));
    addSocket(Socket("toExt"));
}

void BatteryController::process(Message *m){
    if (m->getName() == "getStatus") {
        //On demande le voltage à la batterie et on attend sa réponse:
        getSocketByName("toBattery")->send(new StringMessage("getVoltage", "nothing", 5));
    }
    if (m->getName() == "actualVoltage") {
        StringMessage *sm;
        sm = dynamic_cast<StringMessage *>(m);
        //Reponse de la batterie:
        if (atoi(sm->getPayload().c_str()) > 10) {
            //Si voltage suffisant:
            CLI::getInstance().log(CLI::INFO, "Status OK");
        }
        else {
            CLI::getInstance().log(CLI::INFO, "Status KO: Insufficient voltage");
        }
    }
}