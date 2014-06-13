#include "BatteryController.h"

using namespace std;


BatteryController::BatteryController(Params params) : Module("BatteryController", params, "BatteryModule/BatteryController.xml"){
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
            HCIs::getInstance().log(HCI::INFO, "Status OK");
        }
        else {
            HCIs::getInstance().log(HCI::INFO, "Status KO: Insufficient voltage");
        }
    }
}