#include "Thermique.h"
using namespace std;

Thermique::Thermique(std::string name, Params params) : Module(name, params, "Satellite/Plateforme/Thermique/Thermique.xml"){

}
Thermique::~Thermique() {

}

void Thermique::process(shared_ptr<Message> m){
    
    if(m->getName() == "getTemp") {
        getSocketByName("toODB")->send(Message::createMessage("opTemp", (float) getParamValueByName("temperature"),5));
    }
    
    if(m->getName() == "getTension") {
        getSocketByName("toODB")->send(Message::createMessage("opTension", (float) getParamValueByName("tension"),5));
    }

}
