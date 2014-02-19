#pragma once

#include <vector>

#include <Memory.h>
#include <Message.h>
#include <Socket.h>

/*!
* \class Module
* \brief Les briques de base du simulateur
*
* Il s'agit de la classe centrale du simulateur, qui sera construit comme un assemblage de modules qui communiquent entre eux.
* Il s'agit d'une classe virtuelle.
*/

class Module
{
private:
    Memory mem;                     /*!< La mémoire du module */
    std::vector<Socket> sockets;    /*!< Les connecteurs du module */
    std::vector<Message> messages;  /*!< Les messages compris par le module */

public:
    /*!
    * \fn Module()
    * \brief Constructeur
    */
    Module();

    /*!
    * \fn virtual ~Module()
    * \brief Destructeur
    */
    virtual ~Module();
};