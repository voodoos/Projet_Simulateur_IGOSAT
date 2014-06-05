#pragma once
#include <iostream>
#include "Magnetometre.h"
#include "Module.h"
/*!
* \class SCAO
* \brief Description d'un module
*
*/
class SCAO:public Module{
public:
 SCAO(std::string name, Params params = Params());
 virtual ~SCAO();
private:
 virtual void process(std::shared_ptr<Message>);
};
