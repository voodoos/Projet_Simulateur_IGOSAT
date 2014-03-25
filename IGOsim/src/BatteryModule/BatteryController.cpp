#include "BatteryController.h"

using namespace std;


BatteryController::BatteryController(Params params) : Module("Battery Controller", params){
    //Les messages compris par le controlleur:
    addMessage("getStatus", 5);
    addMessage("actualVoltage", 5);

    //Les connecteurs:
    addSocket(Socket("toBattery"));
    addSocket(Socket("toExt"));
}

void BatteryController::process(std::shared_ptr<Message> m){
    if (m->getName() == "getStatus") {
        //On demande le voltage à la batterie et on attend sa réponse:
        getSocketByName("toBattery")->send(Message::createMessage("getVoltage", "nothing", 5));
    }
    if (m->getName() == "actualVoltage") {
        std::shared_ptr<StringMessage> sm = dynamic_pointer_cast<StringMessage>(m);
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