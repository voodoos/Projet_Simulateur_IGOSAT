#pragma once

#include <string>
#include <unordered_map>

/*!
* \class XMLReader
* \brief Classe utilitaire pour la lecture des fichiers d econfiguration
*
* Cette classe singleton fournit des méthodes statiques permettant par exemple de lire la configuration initiale d'un module
*/

class Message;
class XMLReader
{
private:
    static std::string basePath; /*! Le chemin vers le dossier de configuration */
public:
    /*!
    * \fn static XMLReader& getInstance()
    * \brief Retourne l'instance unique du reader
    */
    static XMLReader& getInstance()
    {
        static XMLReader instance;
        return instance;
    }


    /*!
    * \fn static std::unordered_map<std::string, double> readParams(std::string moduleName)
    * \brief Lecture des paramètre du module protant ce nom.
    * Cette fonction recherche le fichier de configuration portant le nom du module, appelle le parser RapidXML puis créé le tableau de paramètres.
    * \todo En cas d'échec, elle lève une exception.
    */
    static std::unordered_map<std::string, double> readParams(std::string);

    /*!
    * \fn static std::string getPath() const
    * \brief Getter statique du chemin vers le dossier de configuration
    */
    static std::string getPath();


    /*!
    * \fn static void setPath(std::string)
    * \brief Setter statique du chemin vers le dossier de configuration
    */
    static void setPath(std::string);

    /*!
    * \fn ~XMLReader()
    * \brief Destructeur
    */
    ~XMLReader();

private:
    XMLReader() {};
    XMLReader(XMLReader const&);          /*!< À ne pas implementer */
    void operator=(XMLReader const&);     /*!< À ne pas implementer */
};