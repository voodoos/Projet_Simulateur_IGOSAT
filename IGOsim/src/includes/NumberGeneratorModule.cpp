//
//  NumberGeneratorModule.cpp
//  IGOSAT
//
//  Created by Владислав Фиц on 19.02.14.
//  Copyright (c) 2014 Vladislav Fitc. All rights reserved.
//

#include "NumberGeneratorModule.h"

NumberGeneratorModule::NumberGeneratorModule()
{
    Message getNumber("getNumber");
    Socket numberOutput("numberOutput", Socket::OUT);
}