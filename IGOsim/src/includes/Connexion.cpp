#include "Connexion.h"

Connexion::Connexion(Socket &in, Socket &out):inSocket(in), outSocket(out){
}

Connexion::~Connexion(){
}
