#include "Battery.h"

using namespace std;

Battery::Battery(Params params) : Module("Battery", params){
    //Les messages compris par la batterie:
    addMessage("getVoltage", 5);

    //Les connecteurs:
    addSocket(Socket("toBatteryController", this->name));

    //Les paramètres:
    unordered_map<string, double> p;
    
}

void Battery::process(std::shared_ptr<Message> m){

    if (m->getName() == "getVoltage") {
        //On renvoie le voltage au controlleur:
        /*! \todo Franhcement on aura plus souvent des double que des string comme payload de message non ? */
        getSocketByName("toBatteryController")->send(Message::createMessage("actualVoltage", to_string(getParamValueByName("voltage"))));
    }
}
