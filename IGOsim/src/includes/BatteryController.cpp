#include "BatteryController.h"


BatteryController::BatteryController(std::string name, Params params):Module(name, params){
}

void BatteryController::process(Message m){
    if (m.getName() == "getStatus") {
        std::cout<< "Battery Status: OK "<< std::endl;
    }
    if (m.getName() == "getTemperatures") {
        getSocketByName("bcSocket").send(Message("getTemp1", "nothing", 5));
        getSocketByName("bcSocket").send(Message("getTemp2", "nothing", 5));
        getSocketByName("bcSocket").send(Message("getTemp3", "nothing", 5));
        getSocketByName("bcSocket").send(Message("getTemp4", "nothing", 5));
    }
    
    if (m.getName() == "showTemperature1") {
        std::cout<< "Temp1 = "<< m.getPayload() <<" C"<< std::endl;
    }
    if (m.getName() == "showTemperature2") {
        std::cout<< "Temp2 = "<< m.getPayload() <<" C"<< std::endl;
    }
    if (m.getName() == "showTemperature3") {
        std::cout<< "Temp3 = "<< m.getPayload() <<" C"<< std::endl;
    }
    if (m.getName() == "showTemperature4") {
        std::cout<< "Temp4 = "<< m.getPayload() <<" C"<< std::endl;
    }
}