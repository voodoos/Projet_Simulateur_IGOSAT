#include "MacroModule.h"

MacroModule::MacroModule()
{
}

MacroModule::MacroModule(Memory<int> mem):Module(mem)
{
}

MacroModule::~MacroModule()
{
}

void MacroModule::addSubModule(Module mod)
{
    this->modules.insert(this->modules.end(), mod);
}

void MacroModule::addConnexion(Connexion con){
    this->connexions.insert(this->connexions.end(), con);
}