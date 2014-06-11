#pragma once
#include <iostream>
#include "Module.h"
/*!
* \class Alimentation
* \brief Description d'un module
*
*/
class Alimentation:public Module{
public:
 Alimentation(std::string name, Params params = Params());
 virtual ~Alimentation();
private:
 virtual void process(std::shared_ptr<Message>);
};
