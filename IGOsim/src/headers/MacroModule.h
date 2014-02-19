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
    MacroModule(Memory<int>);
    
    /*!
     * \fn ~MacroModule()
     * \brief Destructeur
     */
    ~MacroModule();
    
    
    void addSubModule(Module);
    void addConnexion(Connexion);
private:
    std::vector<Module>modules;         /*!< Les sous-modules de module */
    std::vector<Connexion>connexions;   /*!< Les connexions de module */
};