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

void MacroModule::addSubModule(Module* mod, bool timer)
{
    //On ajoute le module à la liste:
    modules.push_back(mod);

    //On branche le timer:
    if (timer) {
        Timer::getInstance().addModule(mod);
    }

}

void MacroModule::addConnexion(Socket *A, Socket *B){
    connexions.push_back(Connexion(A, B));
}
