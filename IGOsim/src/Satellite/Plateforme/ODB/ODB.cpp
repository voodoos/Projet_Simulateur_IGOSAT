
#include "ODB.h"
using namespace std;

ODB::ODB(std::string name, Params params) : Module(name, params, "Satellite/Plateforme/ODB/ODB.xml"){

}
ODB::~ODB() {

}

void ODB::process(shared_ptr<Message>){

}
