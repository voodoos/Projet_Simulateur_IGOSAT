#pragma once

#include <string>
#include <unordered_map>
#include <vector>

/*!
* \class XMLReader
* \brief Classe utilitaire pour la lecture des fichiers de configuration
*
* Cette classe statique fournit des méthodes statiques permettant par exemple de lire la configuration initiale du simulateur dans les fihciers xml
*/

class Message;
class XMLReader
{
private:
    static std::string basePath; /*! Le chemin vers le dossier de configuration */
public:

    /*!
    * \fn static std::unordered_map<std::string, double> readParams(std::string moduleName)
    * \brief Lecture des paramètre du module protant ce nom.
    * Cette fonction recherche le fichier de configuration portant le nom du module, appelle le parser RapidXML puis créé le tableau de paramètres.
    * En cas d'échec, elle lève une exception.
    */
    static std::unordered_map<std::string, double> readParams(std::string);

    /*!
    * \fn static std::unordered_map<std::string, double> readMessages(std::string moduleName)
    * \brief Lecture des méssages compris par le module protant ce nom.
    * Cette fonction recherche le fichier de configuration portant le nom du module, appelle le parser RapidXML puis créé le tableau de messages.
    * En cas d'échec, elle lève une exception.
    */
    static std::unordered_map<std::string, int> readMessages(std::string);
    
    /*!
     * \fn std::vector<std::string> readSockets(std::string moduleName)
     * \brief Lecture des sockets de modile portant ce nom.
     * Cette fonction recherche le fichier de configuration portant le nom du module, appelle le parser RapidXML puis créé le tableau de noms de sockets.
     * En cas d'échec, elle lève une exception.
     */
    static std::vector<std::string> readSockets(std::string);


    /*!
    * \fn static std::string getPath() const
    * \brief Getter statique du chemin vers le dossier de configuration
    */
    static std::string getPath();


    /*!
    * \fn static void setPath(std::string newPath)
    * \brief Setter statique du chemin vers le dossier de configuration
    */
    static void setPath(std::string);

    /*!
    * \fn ~XMLReader()
    * \brief Destructeur
    */
    ~XMLReader();
};