#include "SCAO.h"

using namespace std;

SCAO::SCAO(std::string name, Params params) : Module(name, params, "Satellite/Plateforme/SCAO/SCAO.xml"){
    
    
    //Ajout des composants:
    addSubModule(new Magnetometre());
    addSubModule(new Magnetocoupleurs());
    

}
SCAO::~SCAO() {

}

void SCAO::process(shared_ptr<Message>){

}
