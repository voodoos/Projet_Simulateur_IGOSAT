#pragma once
#include <iostream>
#include "Module.h"
/*!
* \class Magnetometre
* \brief Description d'un module
*
*/
class Magnetometre:public Module{
public:
 Magnetometre(std::string name, Params params = Params());
 virtual ~Magnetometre();
private:
 virtual void process(std::shared_ptr<Message>);
};
