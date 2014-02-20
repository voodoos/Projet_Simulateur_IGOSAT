#pragma once

#include <string>

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
public:
    /*! \enum Socket::stype
    * Simple énumération pour les différents types de sockets
    *
    * \var Socket::stype::IN
    * Caractérise un connecteur d'entrée.
    *
    * \var Socket::stype::OUT
    * Caractérise un connecteur de sortie.
    */
    enum stype { IN, OUT };

private:
    stype type;         /*!< Type du connecteur */
    std::string name;   /*!< Nom du connecteur */

public:
    /*!
    * \fn Socket(std::string name, stype type)
    * \brief Constructeur
    */
    Socket(std::string name, stype type);

    /*!
    * \fn virtual ~Socket()
    * \brief Destructeur
    */
    ~Socket();
};

