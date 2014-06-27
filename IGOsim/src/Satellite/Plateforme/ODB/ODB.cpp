#include "ODB.h"
using namespace std;

ODB::ODB(std::string name, Params params) : Module(name, params, "Satellite/Plateforme/ODB/ODB.xml"){

}
ODB::~ODB() {

}

void ODB::process(shared_ptr<Message> m){
    
    if (m->getName() == "getCharge") {
        //On renvoie la charge au controlleur de l'alimentation :
        getSocketByName("toODBController")->send(Message::createMessage("actualCharge", to_string(getParamValueByName("charge"))));
    }

}
