#pragma once
#include <iostream>
#include "Module.h"
#include "HCI.h"
#include "HCIs.h"
/*!
* \class Magnetometre
* \brief Description d'un module
*
*/
class Magnetometre:public Module{
public:
 Magnetometre(Params params = Params());
 virtual ~Magnetometre();
private:
 virtual void process(std::shared_ptr<Message>);
};
