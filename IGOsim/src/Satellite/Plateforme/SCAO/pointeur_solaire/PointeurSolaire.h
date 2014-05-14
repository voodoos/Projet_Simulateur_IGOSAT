#pragma once
#include <iostream>
#include "Module.h"
/*!
* \class PointeurSolaire
* \brief Description d'un module
*
*/
class PointeurSolaire:public Module{
public:
 PointeurSolaire(std::string name, Params params = Params());
 virtual ~PointeurSolaire();
private:
 virtual void process(std::shared_ptr<Message>);
};
