#pragma once

#include <string>
#include <queue>
#include "Message.h"
#include "Connexion.h"
#include "ISynchronized.h"
#include <memory>

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
    std::string name;                                    /*!< Nom du connecteur */
    std::string owner;                                   /*!< Nom du module qui possède ce socket */
    std::queue<std::shared_ptr<Message>> messageQueue;   /*!< Boîte de reception des messages */
    Connexion *connexion;                                /*!< Connexion associée à ce Socket */
    int timer;                                           /*!< First message reading time */

public:
    /*!
    * \fn Socket(std::string name, stype type)
    * \brief Constructeur
    */
    Socket(std::string name = "SocketName", std::string owner = "SocketOwner");

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
     * \fn std::string getOwner()
     * \brief Retourne le nom de module qui possede ce socket
     */
    std::string getOwner();
    
    
    /*!
     * \fn void receive(std::shared_ptr<Message>)
     * \brief Met le message m dans la file d'attente de socket
     */
    void receive(std::shared_ptr<Message>);
    
    /*!
     * \fn void send(std::shared_ptr<Message>);
     * \brief Envoye
     */
    void send(std::shared_ptr<Message>);
    
    virtual void clock(int time);
    bool hasMessage();
    std::shared_ptr<Message> getFirstMessage();
    
    /*!
    * \fn  int getTimer() const
    * \brief Renvoie la valeur de timer.
    */
    int getTimer() const;
};

