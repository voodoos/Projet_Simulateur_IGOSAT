#pragma once
#include "HCI.h"
#include "ISynchronized.h"

#include <iostream>
#include <fstream>
#include <vector>

/*!
* \class File
* \brief Implémentation de l'interface via fichier
* Sorties et entrées dans un fichier
*
* Les fichiers sont synchronisés avec le timer pour sortir les données à la fin de chaque tick. Ce mécanisme permet d'afficher plusieurs colonnes de données dans un même fichier provenant de différents modules.
*/

class File :
    public HCI, ISynchronized
{
private:
    mutable std::ofstream file; /*!< Le fichier utilisé */
    std::vector<double> dataBuff; /*!< Le tampon des données (et de leur numéro de colonne) à écrire à chaque pas de temps */
public:
    /*!
    * \fn File(std::string)
    * \brief Ouvre le fichier indiqué, le créé si nécessaire. L'option loglevel ne sert qu'en cas de fichier de log et non de données.
    */
    File(std::string path, logLevel = INFO);
    ~File();

    /*!
    * \fn logv(std::string mess, bool withTime = true) const
    * \brief Affiche le message mess dans le fichier avec ou sans la valeur du timer actuel.
    */
    void logv(std::string, bool = true) const;

    /*!
    * \fn void addData(double, int)
    * \brief Ajout une valeur à la ligne, dans la colonne indiquée par le deuxième argument
    */
    void addData(double, int);

    /*!
    * \fn void clock(int) = 0
    * \brief Méthode appellée à chaque pas de temps pour écrire dans le fichier les données placées dans le buffer
    *
    */
    virtual void clock(int);

private:
    /*!
    * \fn void printStr(std::string)
    * \brief Ecrit la ligne dans le fichier et va à la ligne
    */
    void printStr(std::string) const;

};

