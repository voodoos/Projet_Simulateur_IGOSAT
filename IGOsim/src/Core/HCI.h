#pragma once

#include <string>

#include "Timer.h"

/*!
* \class HCI
* \brief Classe d'abstraction pour l'interface utilisateur (Human Computer Interface)
* Cette interface vise abstraire les interactions avec l'utilisateur pour pouvoir ensutie "facilement" implémenter de nouvelles interfaces, graphiques notamment.
*/

class HCI
{
public:
    /*!
    * Enumération des niveau de logs
    */
    enum logLevel {
        NOTHING = -1,   /*!< Aucun affichage */
        ERROR = 0,      /*!< Erreurs uniquement */
        WARNING = 1,    /*!< Avertissements et erreurs */
        CRITINFO = 2,   /*!< Avertissements, erreurs et informations importantes */
        INFO = 3        /*!< Tous les messages */

    };
protected:
    logLevel logLev; /*!< Niveau de log actuel*/

public:
    /*!
    * \fn HCI(logLevel = INFO)
    * \brief Constructeur par défaut, le log affiche tout
    */
    HCI(logLevel = INFO);

    /*!
    * \fn virtual ~HCI()
    * \brief Destructeur à redéfinir
    */
    virtual ~HCI();

    /*!
    * \fn void setLogLevel(logLevel ll)
    * \brief Change le niveau de log pour ll
    */
    void setLogLevel(logLevel);

    /*!
    * \fn void log(logLevel ll, std::string mess, bool withTime = true) const
    * \brief Demande l'affichagedu message mess, de niveau ll avec ou sans la valeur du timer actuel.
    */
    void log(logLevel, std::string, bool = true) const;

    /*!
    * \fn void logv(std::string mess, bool) const
    * \brief Affiche le message mess avec ou sans la valeur du timer actuel. Cette méthode est virtuelle pure, elle doit être définie dans les classes filles.
    */
    virtual void logv(std::string, bool withTime) const = 0;
};

