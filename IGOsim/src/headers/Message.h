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

public:
    /*!
    * \fn Message(std::string)
    * \brief Constructeur
    */
    Message(std::string name);

    /*!
    * \fn ~Message()
    * \brief Destructeur
    */
    virtual ~Message();
};

