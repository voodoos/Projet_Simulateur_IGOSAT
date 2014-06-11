
#include "Satellite.h"
using namespace std;

Satellite::Satellite(std::string name, Params params) : Module(name, params, "Satellite/Satellite.xml"){

}
Satellite::~Satellite() {

}

void Satellite::process(shared_ptr<Message>){

}
