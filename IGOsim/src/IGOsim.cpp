// IGOsim.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include "Module.h"
#include "MacroModule.h"
#include "Socket.h"


int main()
{
    std::cout << "Hello world" << std::endl;;
    Memory<int> mem;
    Socket pin1("pin1", Socket::IN);
    Socket pin2("pin2", Socket::OUT);
    MacroModule macro(mem);
    macro.addSocket(pin1);
    macro.addSocket(pin2);
    

	return 0;
}


