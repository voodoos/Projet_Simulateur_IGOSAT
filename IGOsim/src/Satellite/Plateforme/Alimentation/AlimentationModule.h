#pragma once
#include <iostream>
#include "MacroModule.h"
#include "Alimentation.h"
#include "AlimentationController.h"


/*!
* \class AlimentationModule
* \brief Description d'un module
*
*/
class AlimentationModule:public MacroModule{
private:
    /*! \todo UNIQUE_PTR POINTER reset(new toto) */
    Alimentation *alimentation;
    AlimentationController *alimentationController;
   
    
public:
 AlimentationModule(std::string name, Params params = Params());
 virtual ~AlimentationModule();
    
private:
 virtual void process(std::shared_ptr<Message>);
};
