#include "MacroModule.h"

#include "HCIs.h"
#include "HCI.h"

//For convenience:
using namespace std;

MacroModule::MacroModule(string name, Params params, string cp) : Module(name, params, cp)
{
}

MacroModule::MacroModule(string name, Memory<int> mem, Params params) : Module(name, mem, params)
{
}

MacroModule::~MacroModule()
{
}

void MacroModule::addSubModule(Module* mod)
{
    //On ajoute le module à la liste en l'encapsulant dans un uniqueptr:
    modules[mod->getName()] = shared_ptr<Module>(mod);
}

void MacroModule::addConnexion(Connexion* c){
    //On ajoute la connexion à la liste en l'encapsulant dans un uniqueptr:
    connexions.push_back(shared_ptr<Connexion>(c));
}

shared_ptr<Module> MacroModule::getModuleByName(string n) {
    //On tente de récupérer le module:
    try {
        shared_ptr<Module> tmp = modules[n];
        if (tmp == nullptr) {
            throw 0;
        }

        return tmp;
    }
    catch (int) {
        HCIs::getInstance().log(HCI::ERROR, "Le module " + n + " n'existe pas dans " + name, false);
        exit(EXIT_FAILURE);
    }
}