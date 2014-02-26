#pragma once

#include <vector>

#include "Memory.h"
#include "Message.h"
#include "Socket.h"


/*!
* \class Module
* \brief Les briques de base du simulateur
*
* Il s'agit de la classe centrale du simulateur, qui sera construit comme un assemblage de modules qui communiquent entre eux.
* Il s'agit d'une classe virtuelle.
*/

class Module
{
protected:
    std::string name;               /*!< Le nom du module */
    Memory<int> memory;             /*!< La mémoire du module */
    std::vector<Socket> sockets;    /*!< Les connecteurs du module */
    std::vector<Message> messages;  /*!< Les messages compris par le module */
public:
    /*!
    * \fn Module()
    * \brief Constructeur
    */
    Module();
    
    Module(Memory<int>);

    /*!
    * \fn virtual ~Module()
    * \brief Destructeur
    */
    virtual ~Module();
    
    void addSocket(Socket);
    Socket *socketWithName(std::string sname);
    void addMessage(Message);
};