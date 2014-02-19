#include "Connexion.h"

Connexion::Connexion(Socket in, Socket out){
    this->inSocket = in;
    this->outSocket = out;
}

Connexion::~Connexion(){
}
