#pragma once

#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
#include <stdexcept>

#include "ISynchronized.h"
#include "Memory.h"
#include "Socket.h"
#include "Message.h"
#include "IntMessage.h"
#include "StringMessage.h"
#include "FloatMessage.h"
#include "StringMessage.h"
#include "Socket.h"
#include "Timer.h"

#define NOP -1 /*! NoOperation valeur de Timer
                        \todo déplacer dans TImer.h*/

/*!
* \class Module
* \brief Les briques de base du simulateur
*
* Il s'agit de la classe centrale du simulateur, qui sera construit comme un assemblage de modules qui communiquent entre eux.
* Il s'agit d'une classe virtuelle. Nécessitant un contrôle de la part du timer, elle implémente l'interface ISynchronized
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
typedef std::unordered_map<std::string, int> Messages;


class Module : public ISynchronized
{
protected:
    std::string name;                           /*!< Le nom du module */
    std::string confPath;                       /*!< Le chemin vers le fichier de configuration */
    Memory<int> memory;                         /*!< La mémoire du module */
    Sockets sockets;                            /*!< Les connecteurs du module */
    Messages messagesAllowed;                   /*!< Les messages compris par le module ET leurs temps d'éxecution */
    Params parameters;                          /*!< Les paramètres d'état du modules */
    std::queue<std::shared_ptr<Message>> tasks; /*!< La file d'attente des messages à traiter */
    int taskTimer;                              /*!< Le timer de la tâche courante */

public:
    /*!
    * \fn Module(std::string = "DefaultName", Params = Params(), std::string cp = "")
    * \brief Constructeur par défault, pour un module sans mémoire.
    */
    Module(std::string = "DefaultName", Params = Params(), std::string cp = "");

    /*!
    * \fn Module(std::string, Memory<int>, Params = Params())
    * \brief Constructeur avec mémoire.
    */
    Module(std::string, Memory<int>, Params = Params());


    /*!
    * \fn virtual ~Module()
    * \brief Destructeur
    */
    virtual ~Module();
    
    /*!
    * \fn void clock(int)
    * \brief Méthode appellée à chaque pas de temps, commune à tous les modules.
    *
    * Cette méthode effectue trois actions, lire les messages arrivés, avancer dans un processus interne, envoyer un message.
    * Ces actions prennent tous du temps: elles peuvent durer plusieurs "ticks".
    */
    virtual void clock(int);

    /*!
    * \fn void addSocket(Socket)
    * \brief Fonction d'ajout d'un connecteur au module.
    */
    void addSocket(Socket);

    /*!
    * \fn void addMessage(std::string msgName, int processingTime)
    * \brief Fonction d'ajout d'un message au module, et de son temps d'éxecution simulé.
    */
    void addMessage(std::string, int);

    /*!
    * \fn Socket *getSocketByName(std::string)
    * \brief Récupère le bon connecteur, ou lève une exception.
    *
    * \todo Créer et gérer l'exception
    */
    Socket* getSocketByName(std::string);

    /*!
    * \fn void getParameterByName(std::string)
    * \brief Récupère la valueur du paramètre, lève une exception sinon.
    *
    * \todo Créer et gérer l'exception
    */
    double getParamValueByName(std::string);
    
    /*!
     * \fn void setParameterByName(std::string, double)
     * \brief Affecter la valueur du paramètre, lève une exception sinon.
     *
     */
    void setParamValueByName(std::string, double);

    /*!
    * \fn bool isMessageAllowed(std::string msgName)
    * \brief Vérifie si le message est un des messages compris par ce module.
    */
    bool isMessageAllowed(std::string);

private:
    /*!
    * \fn void getMessages()
    * \brief Méthode qui à chaque clock entame ou poursuit la lecture des messages
    * 
    * Cette méthode parcours les sockets et rajoute à la file d'attente tasks ceux dont la lecture est terminée.
    */
    void getMessages();

    /*!
    * \fn virtual void process(std::shared_ptr<Message>) = 0
    * \brief La méthode virtuelle pure chargée d'effectuer les actions du module à chaque temps.
    * 
    * Cette méthode, appellée par clock à chaque temps va poursuivre le traitement des tâches en file d'attente.
    *
    */
    virtual void process(std::shared_ptr<Message>) = 0;
};