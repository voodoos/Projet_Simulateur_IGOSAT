
#include "Magnétocoupleurs.h"
using namespace std;

Magnétocoupleurs::Magnétocoupleurs(std::string name, Params params) : Module(name, params, "Satellite/Plateforme/magnetocoupleurs/Magnétocoupleurs.xml"){

}
Magnétocoupleurs::~Magnétocoupleurs() {

}

void Magnétocoupleurs::process(shared_ptr<Message>){
    
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
    
    
    // le magnétocoupleurs corrige l'attitude du satellite (création d'un couple)
    if(m->getName() == "getPosition") {
        getSocketByName("toODB")->send(Message::createMessage("actualPosition", (float) getParamValueByName("km"),5));
    }
    
}
