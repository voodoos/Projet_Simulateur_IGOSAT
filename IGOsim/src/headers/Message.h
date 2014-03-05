#pragma once

#include <string>

/*!
* \class Message
* \brief Classe abstraite de base pour les messages
*
* Les messages sont les différentes informations que peuvent se communiquer les modules.
*
*/

class Message
{
private:
    std::string name; /*!< Nom du message*/
    std::string payload; /*!< Charge utile du message*/
public:
    /*!
    * \fn Message(std::string)
    * \brief Constructeur
    */
    Message(std::string name = "Default Name", std::string payload = "");

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
};

