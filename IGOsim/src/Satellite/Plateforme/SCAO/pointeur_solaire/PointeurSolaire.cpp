
#include "PointeurSolaire.h"
using namespace std;

PointeurSolaire::PointeurSolaire(std::string name, Params params) : Module(name, params, "PointeurSolaire.xml"){

}
PointeurSolaire::~PointeurSolaire() {

}

void PointeurSolaire::process(shared_ptr<Message>){
    
    //mesure de la température
    if(m->getName() == "getTemp") {
        getSocketByName("toODB")->send(Message::createMessage("opTemp", (float) getParamValueByName("temperature"),5));
    }
    
    //mesure de la tension
    if(m->getName() == "getTension") {
        getSocketByName("toODB")->send(Message::createMessage("opTension", (float) getParamValueByName("tension"),5));
    }
    
    
    // l'ODB envoie une commande de controle d'attitude pour mesurer l'orientation
    /*if(m->getName() == "mesureChampMagn") {
     getSocketByName("toSCAO")->send(Message::createMessage("mesureChampMagn", (float) getParamValueByName("tesla"),5));
     }*/
    
    
    // le magnétomètre mesure le champ magnétique
    if(m->getName() == "getChampMagn") {
        getSocketByName("toODB")->send(Message::createMessage("opChampMagn", (float) getParamValueByName("tesla"),5));
    }

}
