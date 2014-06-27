
#include "Alimentation.h"
using namespace std;

Alimentation::Alimentation(std::string name, Params params) : Module(name, params, "Satellite/Plateforme/Alimentation/Alimentation.xml"){
    //Les paramËtres:
    unordered_map<string, double> p;

}
Alimentation::~Alimentation() {

}

void Alimentation::process(shared_ptr<Message> m){
    
    if (m->getName() == "getCharge") {
        //On renvoie la charge au microcontrolleur de l'alimentation :
        getSocketByName("toAlimentationController")->send(Message::createMessage("actualCharge", to_string(getParamValueByName("charge"))));
    }

}
