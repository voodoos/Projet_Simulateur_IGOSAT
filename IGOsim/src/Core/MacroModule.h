#pragma once

#include <iostream>
#include <vector>
#include "Module.h"
#include "Connexion.h"
#include "ISynchronized.h"
#include "Timer.h"

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
    MacroModule(std::string = "DefaultName", Params = Params(), std::string cp = std::string());

    /*!
    * \fn MacroModule(std::string, Memory<int>, Params = Params())
    * \brief Constructeur avec mémoire
    */
    MacroModule(std::string, Memory<int>, Params = Params());
    
    /*!
     * \fn ~MacroModule()
     * \brief Destructeur
     */
    virtual ~MacroModule();
    
    /*!
    * \fn void addSubModule(Module* mod, bool timer = true)
    * \brief Ajoute un sous-module à la liste et branche le timer si timer = true.
    */
    void addSubModule(Module*);
    void addConnexion(Socket *, Socket *);
    
};