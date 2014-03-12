#pragma once

#include <iostream>
#include <vector>
#include "Module.h"
#include "Connexion.h"
#include "ISynchronized.h"

/*!
 * \class MacroModule
 * \brief
 */

class MacroModule : public Module {
private:
    std::vector<Module*>modules;         /*!< Les sous-modules de module */
    std::vector<Connexion>connexions;   /*!< Les connexions entre les sous-modules */

public:
    
    /*!
     * \fn MacroModule()
     * \brief Constructeur par défaut
     */
    MacroModule(std::string = "DefaultName", Params = Params());

    /*!
    * \fn MacroModule(std::string, Memory<int>, Params = Params())
    * \brief Constructeur avec mémoire
    */
    MacroModule(std::string, Memory<int>, Params = Params());
    
    /*!
     * \fn ~MacroModule()
     * \brief Destructeur
     */
    ~MacroModule();
    
    
    void addSubModule(Module*);
    void addConnexion(Connexion);
    
};