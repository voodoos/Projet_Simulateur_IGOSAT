#include "Connexion.h"
#include "Socket.h"

Connexion::Connexion(Socket *a, Socket *b){
    this->socketA = a;
    a->setConnexion(*this);
    this->socketB = b;
    b->setConnexion(*this);
}

Connexion::~Connexion(){
}

void Connexion::dispatch(Message m, Socket *s){
    if (s->getName() == socketA->getName()) {
        socketB->receive(m);
    } else if(s->getName() == socketB->getName()) {
        socketA->receive(m);
    } else {
        std::cout << "Unrecognized sender" << std::endl;
    }
}
