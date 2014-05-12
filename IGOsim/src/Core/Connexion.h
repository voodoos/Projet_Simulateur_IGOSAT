#pragma once

#include <iostream>
#include "Message.h"
#include <memory>

/*!
 * \class Connexion
 * \brief Cette classe représente les tuyaux qui relient les Socket
 */

class Socket;
class Connexion{
public:
    /*!
     * \fn Connexion(Socket *, Socket *)
     * \brief Constructeur, on créé une nouvelle connexion entre deux sockets en les informant mutuellement de leur compagnon (d'infortune ?). 
     */
    Connexion(Socket *a, Socket *b);

    /*!
    * \fn Connexion(Socket *, Socket *)
    * \brief Constructeurpar copie.
    */
    Connexion(const Connexion&);

    /*!
     * \fn ~Connexion()
     * \brief Destructeur
     */
    ~Connexion();
    
    /*!
     * \fn dispatch(std::shared_ptr<Message>, Socket *)
     * \brief Envoie un message m d'un socket s vers son destinataire
     */
    void dispatch(std::shared_ptr<Message>, Socket*) const;

private:
    Socket *socketA; /*!< Premier socket de la connexion */
    Socket *socketB; /*!< Deuxième socket de la connexion */
};