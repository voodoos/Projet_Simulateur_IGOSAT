#pragma once
#include <unordered_map>
#include <string>
#include <sstream>
#include <iostream>

/*!
* \class Memory
* \brief Représente une mémoire
*
* La mémoire est ici simplement modélisée comme une liste de clées et de valeurs, associée à des contraintes.
*/
template <class T>
class Memory
{
private:
    std::unordered_map<std::string, T> cells; /*!< Les cellules de mémoire */
public:
    /*!
    * \fn Memory()
    * \brief Constructeur
    */
    Memory();
    
    /*!
     * \fn Memory(std::unordered_map<std::string, T>)
     * \brief Constructeur parametrisé avec cells
     */
    Memory(std::unordered_map<std::string, T>);
    
    /*!
     * \fn  unsigned int getSize();
     * \brief Retourne la taille courante de la mémoire
     */
    unsigned int getSize();
    
    /*!
     * \fn  int setValueForKey(std::string key, T value);;
     * \brief écrit une valeur "value" dans la case mémoire avec un nom "key"
     */
    int setValueForKey(std::string, T);

    /*!
    * \fn ~Memory()
    * \brief Destructeur
    */
    ~Memory();
};

