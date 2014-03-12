#include "Battery.h"


void Battery::process(Message m){
    std::ostringstream ss;

    if (m.getName() == "showVoltage") {
        std::cout<< "Voltage: "<< getParamValueByName("voltage") <<" V"<< std::endl;
    }
    if (m.getName() == "showAmperage") {
        std::cout<< "Amperage: "<<getParamValueByName("amperage") <<" A"<<std::endl;
    }
    if (m.getName() == "showCapacity") {
        std::cout<< "Capacity: "<< getParamValueByName("capacity") <<" MAh"<< std::endl;
    }
    if (m.getName() == "getTemp1") {
        ss << getParamValueByName("TEMP1");
        getSocketByName("bSocket").send(Message("showTemperature1", std::string(ss.str()), 5));
    }
    if (m.getName() == "getTemp2") {
        ss << getParamValueByName("TEMP2");
        getSocketByName("bSocket").send(Message("showTemperature2", std::string(ss.str()), 5));
    }
    if (m.getName() == "getTemp3") {
        ss << getParamValueByName("TEMP3");
        getSocketByName("bSocket").send(Message("showTemperature3", std::string(ss.str()), 5));
    }
    if (m.getName() == "getTemp4") {
        ss << getParamValueByName("TEMP4");
        getSocketByName("bSocket").send(Message("showTemperature4", std::string(ss.str()), 5));
    }
}

Battery::Battery(std::string name, Params params):Module(name, params){
}