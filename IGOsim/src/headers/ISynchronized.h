#pragma once
/*!
 * \interface ISynchronized
 * \brief Interface à réaliser pour les composantes synchrones
 *
 * Les sockets modélisent les connections entre les modules.
 * Un connecteur peut-être soit un connecteur d'entrée, \a InSocket, soit un connecteur de sortie, \a OutSOcket.
 * Les connecteurs sont reliés entre-eux via les objets Connexion.
 */
class ISynchornized
{
public:
    /*!
     * \fn virtual ~ISynchornized()
     * \brief Destructeur
     */
    virtual ~ISynchornized() {};
    
    /*!
     * \fn virtual void clock(int time)
     * \brief Methode appellé à chaque tick d'horloge liée
     */
    virtual void clock(int time) = 0;
};