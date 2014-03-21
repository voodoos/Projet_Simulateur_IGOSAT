#pragma once

#include <iostream>
#include "Message.h"
/*!
 * \class IntMessage
 * \brief Classe de messages contenant entier comme le payload
 */
class IntMessage: public Message{
private:
    int payload;
public:
    /*!
     * \fn Message(std::string name, int payload, int time)
     * \brief Constructeur
     */
    IntMessage(std::string name, int payload, int time=0);
    
    /*!
     * \fn int getPayload()
     * \brief Renvoie la charge utile du message
     */
    int getPayload();
    
    /*!
     * \fn std::ostream& operator<<(std::ostream &os)
     * \brief Operateur de sortie surchargé
     */
    std::ostream &operator<<(std::ostream &os);
};