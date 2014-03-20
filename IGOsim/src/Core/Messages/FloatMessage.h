#pragma once

#include <iostream>
#include "Message.h"

/*!
 * \class FloatMessage
 * \brief Classe de messages contenant un nombre à virgule flottante comme le payload
 */

class FloatMessage: public Message{
private:
    float payload;
public:
    /*!
     * \fn Message(std::string name, float payload, int time)
     * \brief Constructeur
     */
    FloatMessage(std::string name, float payload, int time=0);
    
    /*!
     * \fn float getPayload()
     * \brief Renvoie la charge utile du message
     */
    float getPayload();
    
    /*!
     * \fn std::ostream& operator<<(std::ostream &os)
     * \brief Operateur de sortie surchargé
     */
    std::ostream& operator<<(std::ostream &os);
};