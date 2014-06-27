#include "AlimentationModule.h"
using namespace std;

AlimentationModule::AlimentationModule(std::string name, Params params) : MacroModule(name, params, "Satellite/Plateforme/Alimentation/AlimentationModule.xml"){
    



}
AlimentationModule::~AlimentationModule() {

}

void AlimentationModule::process(shared_ptr<Message>){

}
