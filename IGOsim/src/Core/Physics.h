#pragma once

#include "ISynchronized.h"

#include <memory>

/*!
* \class Physics
* \brief Classe abstraite pour décrire les différentes actions de l'environnement sur les modules
*
* Elle prend en attribut un module dont elle à le droit de changer les paramètres.
*
*/
class Module;
class Physics : public ISynchronized
{
protected:
    std::shared_ptr<Module> module; /*!< Module associé à cette physique */
    
public:
    /*!
    * \fn  Physics(std::shared_ptr<Module> mod)
    * \brief Construit une classe physique associée au module mod
    *
    */
    Physics(std::shared_ptr<Module>);
    /*!
    * \fn virtual ~Physics()
    * \brief Destructeur à redéfinir
    *
    */
    virtual ~Physics();

    /*!
    * \fn void clock(int) = 0
    * \brief Méthode appellée à chaque pas de temps
    *
    */
    virtual void clock(int) = 0;
};

