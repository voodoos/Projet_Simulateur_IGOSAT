#pragma once
#include <iostream>
#include "Module.h"
#include <vector>


class Timer
{
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

    std::vector<Module *> synchronizedModules; /*!< Les modules synchronisés avec Timer */
    unsigned int counter;
    Timer() {};
    Timer(Timer const&);              /*!< À ne pas implementer */
    void operator=(Timer const&);     /*!< À ne pas implementer */
};