#pragma once

#include <string>
#include <memory>

/*!
* \class Message
* \brief Classe abstraite de base pour les messages
*
* Les messages sont les différentes informations que peuvent se communiquer les modules.
* Un message est composé de son nom, éventuellement d'une donnée (payload),
* et d'une indication temporelle concernant la durée de son envoi et de sa réception.
*/

class Message
{
protected:
    std::string name;                  /*!< Nom du message*/
    unsigned int transmissionTime;     /*!< Temps de traitement du message*/

public:
    /*!
    * \fn Message(std::string)
    * \brief Constructeur par défaut
    */
    Message(std::string name = "Default Name", int = 0);

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
     * \fn std::ostream& operator<<(std::ostream &os)
     * \brief Operateur de sortie surchargé
     */
    virtual std::ostream &operator<<(std::ostream &os)=0;
    
    /*!
    * \fn int getTransmissionTime()
    * \brief Renvoie le temps de traitement du message
    */
    unsigned int getTransmissionTime();
    
    /*!
     * \fn std::shared_ptr<Message> createMessage(std::string, int=0, unsigned=0)
     * \brief Crée et retourne le pointeur partagé au nouveau IntMessage
     */
    static std::shared_ptr<Message> createMessage(std::string, int=0, unsigned int=0);
    
    /*!
     * \fn std::shared_ptr<Message> createMessage(std::string, std::string="", unsigned=0)
     * \brief Crée et retourne le pointeur partagé au nouveau StringMessage
     */
    static std::shared_ptr<Message> createMessage(std::string, std::string="", unsigned int=0);
    
    /*!
     * \fn std::shared_ptr<Message> createMessage(std::string, float=0, unsigned=0)
     * \brief Crée et retourne le pointeur partagé au nouveau FloatMessage
     */
    static std::shared_ptr<Message> createMessage(std::string, float=0, unsigned=0);
};


