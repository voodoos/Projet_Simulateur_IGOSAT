#include <iostream>
#include "Message.h"
#pragma once
/*!
 * \class Connexion
 * \brief
 */

class Socket;
class Connexion{
public:
    /*!
     * \fn Connexion(Socket *, Socket *)
     * \brief Constructeur
     */
    Connexion(Socket *a, Socket *b);
    /*!
     * \fn ~Connexion()
     * \brief Destrcuteur
     */
    ~Connexion();
    
    void dispatch(Message m, Socket *s);
private:
    Socket *socketA;
    Socket *socketB;
};