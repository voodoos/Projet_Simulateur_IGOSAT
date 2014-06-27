#pragma once
#include <iostream>

#include "Alimentation.h"
#include "AlimentationController.h"
#include "ODB.h"
#include "ODBmicroController.h"


#include "MacroModule.h"
/*!
* \class ODBModule
* \brief Description d'un module
*
*/
class ODBModule:public MacroModule{
private:
    /*! \todo UNIQUE_PTR POINTER reset(new toto) */
    Alimentation *alimentation;
    AlimentationController *alimentationController;
    ODBmicroController *oDBmicroController;
    ODB *oDB;

    
    
public:
 ODBModule(std::string name, Params params = Params());
 virtual ~ODBModule();
    
private:
 virtual void process(std::shared_ptr<Message>);
};
