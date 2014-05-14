#pragma once
#include <iostream>
#include "Module.h"
/*!
* \class Magnétocoupleurs
* \brief Description d'un module
*
*/
class Magnétocoupleurs:public Module{
public:
 Magnétocoupleurs(std::string name, Params params = Params());
 virtual ~Magnétocoupleurs();
private:
 virtual void process(std::shared_ptr<Message>);
};
