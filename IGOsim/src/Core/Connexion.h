#pragma once

#include <iostream>
#include "Message.h"

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

    Connexion(const Connexion&);

    /*!
     * \fn ~Connexion()
     * \brief Destructeur
     */
    ~Connexion();
    
    /*!
     * \fn dispatch(Message, Socket *)
     * \brief Envoye un message m reçu de socket s vers le socket d'un autre côté
     */
    void dispatch(Message m, Socket *s);
private:
    Socket *socketA;
    Socket *socketB;
};