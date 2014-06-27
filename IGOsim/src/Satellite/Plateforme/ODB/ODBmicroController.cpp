#include "ODBmicroController.h"

using namespace std;

ODBmicroController::ODBmicroController(std::string name, Params params) : Module(name, params, "Satellite/Plateforme/ODB/ODBmicroController.xml"){

}
ODBmicroController::~ODBmicroController() {

}

void ODBmicroController::process(shared_ptr<Message> m){
    
    if (m->getName() == "getStatus") {
        //On demande le pourcentage de charge de la batterie et on attend sa réponse:
        getSocketByName("toODBmicroController")->send(Message::createMessage("getCharge", "nothing", 5));
    }
    if (m->getName() == "actualCharge") {
        std::shared_ptr<StringMessage> sm = dynamic_pointer_cast<StringMessage>(m);
        //Reponse de la batterie:
        if (atoi(sm->getPayload().c_str()) > 30) {
            //Si le charge est suffisante et est donc supérieur à 30 % :
            HCIs::getInstance().log(HCI::INFO, "Status OK");
        }
        else {
            HCIs::getInstance().log(HCI::INFO, "Status KO: charge de la batterie insuffisante");
        }
    }

}
