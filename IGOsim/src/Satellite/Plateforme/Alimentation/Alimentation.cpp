
#include "Alimentation.h"
using namespace std;

Alimentation::Alimentation(std::string name, Params params) : Module(name, params, "Satellite/Plateforme/Alimentation/Alimentation.xml"){

}
Alimentation::~Alimentation() {

}

void Alimentation::process(shared_ptr<Message>){

}
