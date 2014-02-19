#pragma once

#include <iostream>
#include <vector>
#include "Module.h"
#include "Connexion.h"

/*!
 * \class MacroModule
 * \brief
 */

class MacroModule:public Module{
public:
    
    /*!
     * \fn MacroModule()
     * \brief Constructeur
     */
    MacroModule();
    
    /*!
     * \fn ~MacroModule()
     * \brief Destructeur
     */
    ~MacroModule();
    
private:
    
    std::vector<Module>modules;         /*!< Les sous-modules de module */
    std::vector<Connexion>connexions;   /*!< Les connexions de module */
};