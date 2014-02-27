#pragma once

#include <iostream>
#include <vector>
#include "Module.h"
#include "Connexion.h"

/*!
 * \class MacroModule
 * \brief
 */

class MacroModule :public Module{
private:
    std::vector<Module>modules;         /*!< Les sous-modules de module */
    std::vector<Connexion>connexions;   /*!< Les connexions entre les sous-modules */

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
};