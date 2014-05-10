#pragma once
#include "HCI.h"


/*!
* \class CLI
* \brief Implémentation de l'interface en ligne de commande (Command Line Interface)
* Sorties et entrées via la ligne de commande. Une seule instance possible de celle-ci, le pattern singleton a été utilisé.
*/
class CLI :
    public HCI
{
public:
    /*!
    * \fn static CLI& getInstance()
    * \brief Retourne l'instance unique de CLI
    */
    static CLI& getInstance()
    {
        static CLI instance;
        return instance;
    }

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


private:
    CLI(logLevel ll = INFO) {};
    CLI(CLI const&);                /*!< À ne pas implémenter, nécessaire au pattern singleton */
    void operator=(CLI const&);     /*!< À ne pas implémenter, nécessaire au pattern singleton */
};

