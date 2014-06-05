#pragma once
#include <iostream>
#include "Module.h"
/*!
* \class Thermique
* \brief Module du sous-système d'actuateurs thermiques.
*
*/
class Thermique:public Module{
public:
 Thermique(std::string name, Params params = Params());
 virtual ~Thermique();
private:
 virtual void process(std::shared_ptr<Message> m);
};
