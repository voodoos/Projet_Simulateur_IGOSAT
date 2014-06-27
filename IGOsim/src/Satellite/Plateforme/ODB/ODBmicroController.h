#pragma once
#include <iostream>
#include "HCI.h"
#include "HCIs.h"

#include "Module.h"
/*!
* \class ODBmicroController
* \brief Description d'un module
*
*/
class ODBmicroController:public Module{
public:
 ODBmicroController(std::string name, Params params = Params());
 virtual ~ODBmicroController();
private:
 virtual void process(std::shared_ptr<Message>);
};
