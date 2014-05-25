#pragma once
#include <iostream>
#include <vector>

#include "ISynchronized.h"


/*!
* \class Timer
* \brief Cette classe sert à la gestion du temps simulé
*
* C'est le timer (unique) qui a pour rôle de synchroniser l'ensemble du simulateur
* et de donner les informations intéresantes sur le temps simulé.
*
*/

class File;
class Physics;
class Module;
class Timer
{
private:

    std::vector<Module *> synchronizedModules; /*!< Les modules synchronisés avec Timer */
    std::vector<Physics *> synchronizedPhysics; /*!< Les modules physiques synchronisés */
    std::vector<File *> synchronizedFiles; /*!< Les fichiers synchronisés */
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
    * \fn void add(Module *m)
    * \brief Ajouter le pointeur du module dans le tableau des modules synchronisés
    */
    void add(Module *);

    /*!
    * \fn void add(Physics *m)
    * \brief Ajouter le pointeur du module physique dans le tableau des modules synchronisés
    */
    void add(Physics *);

    /*!
    * \fn void add(File *m)
    * \brief Ajouter un fichier synchronisé
    */
    void add(File *f);

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