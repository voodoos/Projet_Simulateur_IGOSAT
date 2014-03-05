#include "Battery.h"


void Battery::process(Message m){
    if (m.getName() == "showVoltage") {
        std::cout<< "Voltage: "<< getParamValueByName("voltage") <<" V"<< std::endl;
    }
    if (m.getName() == "showAmperage") {
        std::cout<< "Amperage: "<<getParamValueByName("amperage") <<" A"<<std::endl;
    }
    if (m.getName() == "showCapacity") {
        std::cout<< "Capacity: "<< getParamValueByName("capacity") <<" MAh"<< std::endl;
    }
}

Battery::Battery(std::string name, Params params){
    this->name = name;
    this->parameters = params;
}