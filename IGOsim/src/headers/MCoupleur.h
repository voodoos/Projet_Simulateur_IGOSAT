//
//  MCoupleur.h
//  simulateur
//
//  Created by Colin Louis González Duburc on 3/14/14.
//  Copyright (c) 2014 IGOsat. All rights reserved.
//

#ifndef simulateur_MCoupleur_h
#define simulateur_MCoupleur_h

#include <iostream>
#include "Module.h"

#endif

class MCoupleur: public Module
{
private :
    void process(Message);
public :
    MCoupleur(Params = Params());
};

