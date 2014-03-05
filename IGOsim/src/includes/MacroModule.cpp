#include "MacroModule.h"

//For convenience:
using namespace std;

MacroModule::MacroModule(string name, Params params) : Module(name, params)
{
}

MacroModule::MacroModule(string name, Memory<int> mem, Params params) : Module(name, mem, params)
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