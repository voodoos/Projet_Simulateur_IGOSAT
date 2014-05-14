
#include "PointeurSolaire.h"
using namespace std;

PointeurSolaire::PointeurSolaire(std::string name, Params params) : Module(name, params, "PointeurSolaire.xml"){

}
PointeurSolaire::~PointeurSolaire() {

}

void PointeurSolaire::process(shared_ptr<Message>){

}
