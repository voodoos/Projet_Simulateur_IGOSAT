#include "Battery.h"

using namespace std;

Battery::Battery(Params params) : Module("Battery", params){
    //Les messages compris par la batterie:
    addMessage(Message("getVoltage", "nothing", 5), 5);

    //Les connecteurs:
    addSocket(Socket("toBatteryController"));

    //Les paramètres:
    unordered_map<string, double> p;
    
}

void Battery::process(Message m){

    if (m.getName() == "getVoltage") {
        //On renvoie le voltage au controlleur:
        /*! \todo Franhcement on aura plus souvent des double que des string comme payload de message non ? */
        getSocketByName("toBatteryController")->send(Message("actualVoltage", to_string(getParamValueByName("voltage"))));
    }
}
