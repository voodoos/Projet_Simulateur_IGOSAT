#pragma once
#include <iostream>
#include "Module.h"
/*!
* \class Satellite
* \brief Description d'un module
*
*/
class Satellite:public Module{
public:
 Satellite(std::string name, Params params = Params());
 virtual ~Satellite();
private:
 virtual void process(std::shared_ptr<Message>);
};
