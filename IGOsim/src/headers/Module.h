#pragma once

#include <string>
#include <unordered_map>
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


/*!
* \typedef typedef std::unordered_map<std::string, double> Params
* \brief Un raccourci pratique pour une hashtable de paramètres
*/
typedef std::unordered_map<std::string, double> Params;

/*!
* \typedef typedef std::unordered_map<std::string, Socket> Sockets
* \brief Un raccourci pratique pour une hashtable de sockets
*/
typedef std::unordered_map<std::string, Socket> Sockets;

/*!
* \typedef typedef std::unordered_map<std::string, Message> Messages
* \brief Un raccourci pratique pour une hashtable de messages
*/
typedef std::unordered_map<std::string, Message> Messages;

class Module
{
protected:
    std::string name;                       /*!< Le nom du module */
    Memory<int> memory;                     /*!< La mémoire du module */
    Sockets sockets;                        /*!< Les connecteurs du module */
    Messages messages;                      /*!< Les messages compris par le module */
    Params parameters;                      /*!< Les paramètres d'état du modules */
public:
    /*!
    * \fn Module(std::string = "DefaultName", Params = Params())
    * \brief Constructeur par défault, pour un module sans mémoire
    */
    Module(std::string = "DefaultName", Params = Params());

    /*!
    * \fn Module(std::string, Memory<int>, Params = Params())
    * \brief Constructeur avec mémoire
    */
    Module(std::string, Memory<int>, Params = Params());


    /*!
    * \fn virtual ~Module()
    * \brief Destructeur
    */
    virtual ~Module();
    
    /*!
    * \fn virtual ~Module()
    * \brief Destructeur
    */

    /*!
    * \fn void addSocket(Socket)
    * \brief Fonction d'ajout d'un connecteur au module
    */
    void addSocket(Socket);

    /*!
    * \fn void addMessage(Message)
    * \brief Fonction d'ajout d'un message au module
    */
    void addMessage(Message);

    /*!
    * \fn Socket *getSocketByName(std::string)
    * \brief Récupère le bon connecteur, ou lève une exception
    *
    * \todo Créer et gérer l'exception
    */
    Socket& getSocketByName(std::string);

    /*!
    * \fn void getParameterByName(std::string)
    * \brief Récupère la valueur du paramètre, lève une exception sinon
    *
    * \todo Créer et gérer l'exception
    */
    double getParamValueByName(std::string);
};