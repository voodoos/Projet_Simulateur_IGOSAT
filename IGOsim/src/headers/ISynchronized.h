#pragma once

/*!
* \class ISynchronized
* \brief Interface pour ÈlÈment synchronisÈ
*
* Cette interface vise ‡ homogÈnÈiser la notion de temps (timer) pour les classes qui en dÈpendent.
*/

class ISynchronized
{
public:
    /*!
     * \fn virtual ~ISynchornized()
     * \brief Destructeur
     */
    virtual ~ISynchronized(){};
    
    /*!
     * \fn virtual void clock(int time)
     * \brief Methode appellé à chaque tick d'horloge liée
     */
    virtual void clock(int time) = 0;
};