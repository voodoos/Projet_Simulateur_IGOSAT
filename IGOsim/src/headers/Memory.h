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
    std::unordered_map<std::string, T> cells; /*!< Les cellules de memoire */
public:
    /*!
    * \fn Memory()
    * \brief Constructeur
    */
    Memory();
    
    /*!
     * \fn Memory(std::unordered_map<std::string, T>)
     * \brief Constructeur parametrisŽ avec cells
     */
    Memory(std::unordered_map<std::string, T>);
    
    /*!
     * \fn  unsigned int getSize();
     * \brief Retourne la taille courante de la memoire
     */
    unsigned int getSize();
    
    /*!
     * \fn  int setValueForKey(std::string key, T value);;
     * \brief ƒcrit une valeur "value" dans la case memoire avec un nom "key"
     */
    int setValueForKey(std::string, T);

    /*!
    * \fn ~Memory()
    * \brief Destructeur
    */
    ~Memory();
};

