#pragma once

#include "HCI.h"

#include <unordered_map>

/*!
* \class HCIs
* \brief Factory pour les différentes interfaces
* Cette classe singleton utilitaire permet de gérer les différentes interfaces utilisées par le simulateur.
* 
*/
class File;
class HCIs
{
private:
    bool loggerSet;                     /*!< Logger configuré ou non */
    HCI* logger;                        /*!< Logger a utiliser */
    std::unordered_map<std::string, File*> dataOutputs;    /*!< Fichiers de données */
public:
    /*!
    * \fn static HCIs& getInstance()
    * \brief Retourne l'instance unique de HCIs
    */
    static HCIs& getInstance()
    {
        static HCIs instance;
        return instance;
    }

    /*!
    * \fn HCIs(HCI::logLevel = HCI::INFO)
    * \brief Initialise le logging via ligne de commande (une seule fois !)
    */
    void setLog(HCI::logLevel = HCI::INFO);

    /*!
    * \fn HCIs(std::string, logLevel = INFO)
    * \brief Initialise le logging via fichier (une seule fois !)
    */
    void setLog(std::string, HCI::logLevel = HCI::INFO);

    /*!
    * \fn void log(HCI::logLevel, std::string, bool)
    * \brief Utilise le logger configuré pour logger le message. Si aucun logger n'est configuré, command line par défaut.
    */
    void log(HCI::logLevel, std::string, bool withTime = true);

    /*!
    * \fn void addDataOutput(std::string, std::string)
    * \brief Ajout une nouvelle sortie de données (pour le moment que des fichiers).
    * \todo Abstraire et prévoir d'autres sorties que dans fichiers ?
    */
    void addDataOutput(std::string, std::string);

    /*!
    * \fn File* HCIs::getDataOutput(std::string)
    * \brief Donne un pointeur vers la sortie de données demandée.
    * \todo Exception....
    */
    File* getDataOutput(std::string);

    /*!
    * \fn ~HCIs()
    * \brief Destructeur, ferme les fichiers et autres loggers
    */
    ~HCIs();


private:
    HCIs():loggerSet(false) {};
    HCIs(HCIs const&);                /*!< À ne pas implémenter, nécessaire au pattern singleton */
    void operator=(HCIs const&);     /*!< À ne pas implémenter, nécessaire au pattern singleton */
};

