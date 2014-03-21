#pragma once

#include <iostream>
#include "Message.h"

/*!
 * \class StringMessage
 * \brief Classe de messages contenant une suite des caractères comme le payload
 */
class StringMessage: public Message{
private:
    std::string payload;
public:
    /*!
     * \fn Message(std::string name, std::string payload, int time)
     * \brief Constructeur
     */
    StringMessage(std::string name, std::string payload, int time=0);
    
    /*!
     * \fn std::string getPayload()
     * \brief Renvoie la charge utile du message
     */
    std::string getPayload();
    
    /*!
     * \fn std::ostream& operator<<(std::ostream &os)
     * \brief Operateur de sortie surchargé
     */
    std::ostream& operator<<(std::ostream &os);
};