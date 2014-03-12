#pragma once
#include <iostream>
#include "Physics.h"
#include <vector>

/*!
* \class Timer
* \brief Cette classe sert à la gestion du temps simulé
*
* C'est le timer (unique) qui a pour rôle de synchroniser l'ensemble du simulateur
* et de donner les informations intéresantes sur le temps simulé.
*
*/

class Module;
class Timer
{
private:

    std::vector<ISynchronized *> synchronizedModules; /*!< Les modules synchronisés avec Timer */
    std::vector<ISynchronized *> synchronizedPhysics; /*!< Les modules physiques synchronisés */
    unsigned int counter;                             /*!< Le temps actuel */

public:
    /*!
     * \fn static Timer& getInstance()
     * \brief Retourne l'instance unique de Timer
     */
    static Timer& getInstance()
    {
        static Timer instance;
        return instance;
    }
    
    /*!
     * \fn void addModule(Module *m)
     * \brief Ajouter le pointeur au module dans le tableau des modules synchronisés
     */
    void addModule(Module *);

    /*!
    * \fn void addPhysics(Physics *m)
    * \brief Ajouter le pointeur au module dans le tableau des modules synchronisés
    */
    void addPhysics(Physics *);
    
    /*!
     * \fn void start(unsigned int);
     * \brief Lancer le Timer
     */
    void start(unsigned int c = 100);
    
    /*!
     * \fn void stop();
     * \brief Arreter le Timer
     */
    void stop();
    
    /*!
     * \fn unsigned int getCounter() const
     * \brief Retourne la valeur de compteur
     */
    unsigned int getCounter() const;
    
    /*!
     * \fn void setCounter(unsigned int c)
     * \brief Mettre la valeur c dans le compteur
     */
    void setCounter(unsigned int);

private:
    Timer() {};
    Timer(Timer const&);              /*!< À ne pas implementer */
    void operator=(Timer const&);     /*!< À ne pas implementer */
};