// IGOsim.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include "Module.h"
#include "MacroModule.h"
#include "Socket.h"
#include "Battery.h"
#include "Timer.h"


int main()
{
    std::cout << "Hello space!" << std::endl;;
    
    std::unordered_map<std::string, double> p;

    //Exemple de batterie:
    p["voltage"] = 12;
    p["amperage"] = 0.2;
    p["capacity"] = 10000;

    Message m1("showVoltage", "nothing", 5);
    Message m2("showAmperage", "nothing", 5);
    Message m3("showCapacity", "nothing", 5);


    Battery b1 = Battery("Battery1", p);
    b1.addMessage(m1, 5);
    b1.addMessage(m2, 5);
    b1.addMessage(m3, 5);
    b1.addSocket(Socket("batteryIN"));
    
    Timer::getInstance().addModule(&b1);
    b1.getSocketByName("batteryIN").receive(m1);
    b1.getSocketByName("batteryIN").receive(m2);
    b1.getSocketByName("batteryIN").receive(m3);
    
    Timer::getInstance().start(100);

	return 0;
}


