#pragma once
#include <iostream>
#include "Module.h"
#include "HCI.h"
#include "HCIs.h"


/*!
* \class AlimentationController
* \brief Description d'un module
*
*/
class AlimentationController:public Module{
public:
 AlimentationController(std::string name, Params params = Params());
 virtual ~AlimentationController();
private:
 virtual void process(std::shared_ptr<Message>);
};
