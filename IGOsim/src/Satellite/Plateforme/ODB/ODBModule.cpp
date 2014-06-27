#include "ODBModule.h"
using namespace std;

ODBModule::ODBModule(std::string name, Params params) : MacroModule(name, params, "Satellite/Plateforme/ODB/ODBModule.xml"){
    
    //Les modules:
    addSubModule(new ODBmicroController("ODBmicroController"));
    addSubModule(new ODB("ODB"));
    addSubModule(new AlimentationController("AlimentationController"));
    addSubModule(new Alimentation("Alimentation"));
    
    //Les connexions internes:
    /*! \todo Surcharger [] pour getsocketbyname */
    addConnexion(new Connexion(getModuleByName("AlimentationController")->getSocketByName("toAlimentation"), getModuleByName("Alimentation")->getSocketByName("toAlimentationController")));
    addConnexion(new Connexion(getModuleByName("AlimentationController")->getSocketByName("toODBmicroController"), getModuleByName("ODBmicroController")->getSocketByName("toAlimentationController")));
    addConnexion(new Connexion(getModuleByName("ODBmicroController")->getSocketByName("toODB"), getModuleByName("ODB")->getSocketByName("toODBmicroController")));
    addConnexion((new Connexion(this->getSocketByName("ext"), this->getSocketByName("ext"))));


}
ODBModule::~ODBModule() {
    

}

void ODBModule::process(shared_ptr<Message> m){

}
