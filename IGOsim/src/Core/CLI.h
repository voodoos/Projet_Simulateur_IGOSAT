#pragma once
#include "HCI.h"


/*!
* \class CLI
* \brief Implémentation de l'interface en ligne de commande (Command Line Interface)
* Sorties et entrées via la ligne de commande.
*/
class CLI :
    public HCI
{
public:
    /*! CLI(logLevel)
    * \brief Le constructeur qui définit le log level.
    */
    CLI(logLevel = INFO);

    /*!
    * \fn virtual ~CLI()
    * \brief Destructeur
    */
    virtual ~CLI();

    /*!
    * \fn logv(std::string mess, bool withTime = true) const
    * \brief Affiche le message mess dans la ligne de commande avec ou sans la valeur du timer actuel.
    */
    void logv(std::string, bool = true) const;
};

