#pragma once

#include <string>

/*!
* \class Message
* \brief Classe abstraite de base pour les messages
*
* Les messages sont les différentes informations que peuvent se communiquer les modules.
* Un message est composé de son nom, éventuellement d'une donnée (payload),
* et d'une indication temporelle concernant la durée de son envoi et de sa réception.
*/

class Message
{
private:
    std::string name;       /*!< Nom du message*/
    std::string payload;    /*!< Charge utile du message*/
    unsigned int transmissionTime;     /*!< Temps de traitement du message*/

public:
    /*!
    * \fn Message(std::string)
    * \brief Constructeur par défaut
    */
    Message(std::string name = "Default Name", std::string payload = "", int = 0);

    /*!
    * \fn ~Message()
    * \brief Destructeur
    */
    virtual ~Message();

    /*!
    * \fn std::string getName()
    * \brief Renvoie le nom du message
    */
    std::string getName();

    /*!
    * \fn std::string getPayload()
    * \brief Renvoie la charge utile du message
    */
    std::string getPayload();
    
    /*!
    * \fn int getTransmissionTime()
    * \brief Renvoie le temps de traitement du message
    */
    unsigned int getTransmissionTime();
};

