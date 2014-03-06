#pragma once

/*!
* \class ISynchronized
* \brief Interface pour élément synchronisé
*
* Cette interface vise à homogénéiser la notion de temps (timer) pour les classes qui en dépendent.
*/

class ISynchronized
{
public:
    virtual ~ISynchronized() {};
    virtual void clock(int time) = 0;
};