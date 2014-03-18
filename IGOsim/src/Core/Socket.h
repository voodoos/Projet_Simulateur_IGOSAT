﻿#pragma once

#include <string>
#include <queue>
#include "Message.h"
#include "Connexion.h"
#include "ISynchronized.h"

#define NOM -1 /*! NoMessage valeur de Timer*/

/*!
* \class Socket
* \brief Classe abstraite pour les connecteurs des modules
*
* Les sockets modélisent les connections entre les modules.
* Un connecteur peut-être soit un connecteur d'entrée, \a InSocket, soit un connecteur de sortie, \a OutSOcket. 
* Les connecteurs sont reliés entre-eux via les objets Connexion.
*/

/*! \todo Setconnection in Socket must be private and friend with Connection only ! */

class Socket:public ISynchronized
{
private:
    std::string name;                   /*!< Nom du connecteur */
    std::queue<Message> messageQueue;   /*!< Boîte de reception des messages */
    Connexion *connexion;               /*!< Connexion associée à ce Socket */
    int timer;                          /*!< First message reading time */

public:
    /*!
    * \fn Socket(std::string name, stype type)
    * \brief Constructeur
    */
    Socket(std::string name = "DefaultName");

    Socket(const Socket&);

    /*!
    * \fn virtual ~Socket()
    * \brief Destructeur
    */
    ~Socket();
    
    /*!
     * \fn void setConnexion(Connexion c)
     * \brief Branche le socket à la connexion c
     */
    void setConnexion(Connexion &c);
    
    /*!
     * \fn std::string getName()
     * \brief Retourne le nom de socket
     */
    std::string getName();
    
    /*!
     * \fn void receive(Message m)
     * \brief Met le message m dans la file d'attente de socket
     */
    void receive(Message m);
    
    /*!
     * \fn void send(Message m);
     * \brief Envoye
     */
    void send(Message m);
    
    virtual void clock(int time);
    bool hasMessage();
    Message getFirstMessage();
    
    /*!
    * \fn  int getTimer() const
    * \brief Renvoie la valeur de timer.
    */
    int getTimer() const;
};
