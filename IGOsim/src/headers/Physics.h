#pragma once

#include "Module.h"

/*!
* \class Physics
* \brief Classe abstraite pour décrire les différentes actions de l'environnement sur les modules
*
* Prend en attribut un module dont elle à le droit de changer les paramètres.
*
*/

class Physics : public ISynchronized
{
protected:
    Module* module;
    
public:
    Physics(Module *);
    virtual ~Physics();

    /*!
    * \fn void clock(int) = 0
    * \brief Méthode appellée à chaque pas de temps
    *
    */
    virtual void clock(int) = 0;
};

