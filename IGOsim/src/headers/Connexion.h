#pragma once
#include <iostream>
#include "Socket.h"
/*!
 * \class Connexion
 * \brief
 */
class Connexion{
public:
    /*!
     * \fn Connexion()
     * \brief Constructeur
     */
    Connexion(Socket &in, Socket &out);
    /*!
     * \fn ~Connexion()
     * \brief Destrcuteur
     */
    ~Connexion();
private:
    Socket inSocket;
    Socket outSocket;
};