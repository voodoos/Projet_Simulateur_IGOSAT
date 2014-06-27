
#include "Magnetometre.h"
using namespace std;

Magnetometre::Magnetometre(Params params) : Module("Magnetometre", params, "Satellite/Plateforme/SCAO/Magnetometre.xml"){

}
Magnetometre::~Magnetometre() {

}

void Magnetometre::process(shared_ptr<Message> m){

    
    //mesure de la température
  /* if(m->getName() == "getTemp") {
        getSocketByName("toODB")->send(Message::createMessage("temp_min", (float) getParamValueByName("temperature"),5));
    }
    
    //mesure de la tension
    if(m->getName() == "getTension") {
        getSocketByName("toODB")->send(Message::createMessage("opTension", (float) getParamValueByName("tension"),5));
    }*/
   
    
    // l'ODB envoie une commande de controle d'attitude pour mesurer l'orientation
    /*if(m->getName() == "mesureChampMagn") {
     getSocketByName("toSCAO")->send(Message::createMessage("mesureChampMagn", (float) getParamValueByName("tesla"),5));
     }*/
    
    
    // le magnétomètre mesure le champ magnétique
   if(m->getName() == "getChampMagn") {
       stringstream ss;
       ss << getParamValueByName("opChampMagn");
       string message = "Champ Magnetique " + ss.str();
       HCIs::getInstance().log(HCI::INFO, message);

    }
    
    
}
