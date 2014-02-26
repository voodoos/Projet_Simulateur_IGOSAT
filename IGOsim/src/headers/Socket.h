#pragma once

#include <string>
#include <queue>
#include "Message.h"
#include "Connexion.h"

/*!
* \class Socket
* \brief Classe abstraite pour les connecteurs des modules
*
* Les sockets modélisent les connections entre les modules.
* Un connecteur peut-être soit un connecteur d'entrée, \a InSocket, soit un connecteur de sortie, \a OutSOcket. 
* Les connecteurs sont reliés entre-eux via les objets Connexion.
*/

class Socket
{
private:
    std::string name;   /*!< Nom du connecteur */
    std::queue<Message> messageQueue;
    Connexion *connexion;

public:
    /*!
    * \fn Socket(std::string name, stype type)
    * \brief Constructeur
    */
    Socket(std::string name);

    /*!
    * \fn virtual ~Socket()
    * \brief Destructeur
    */
    ~Socket();
    
    void setConnexion(Connexion c);
    std::string getName();
    void receive(Message m);
    void send(Message m);
    bool hasMessage();
    Message getLastMessage();
};

