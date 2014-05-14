#pragma once
#include <iostream>
#include "Module.h"
/*!
* \class ODB
* \brief Description d'un module
*
*/
class ODB:public Module{
public:
 ODB(std::string name, Params params = Params());
 virtual ~ODB();
private:
 virtual void process(std::shared_ptr<Message>);
};
