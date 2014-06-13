#include "Connexion.h"

#include <sstream>

#include "Socket.h"


#include "HCIs.h"
#include "HCI.h"

using namespace std;

Connexion::Connexion(Socket *a, Socket *b) : socketA(a), socketB(b){
    a->setConnexion(*this);
    b->setConnexion(*this);
}

Connexion::Connexion(const Connexion& c) {
    //cout << "Copie de connexion" << endl;
    socketA = c.socketA;
    socketB = c.socketB;

    //On actualise la connexion !
    socketA->setConnexion(*this);
    socketB->setConnexion(*this);
}

Connexion::~Connexion(){
}

void Connexion::dispatch(std::shared_ptr<Message> m, Socket *s){
    std::string msgReceived("");
    if (s->getName() == socketA->getName()) {
        socketB->receive(m);
        msgReceived = "Socket "+socketB->getOwner()+"."+socketB->getName() + " received " + m->getName() + " sent by " + socketA->getOwner()+"."+socketA->getName();
        HCIs::getInstance().log(HCI::INFO, msgReceived);
    } else if(s->getName() == socketB->getName()) {
        socketA->receive(m);
        msgReceived = "Socket "+socketA->getOwner()+"."+socketA->getName() + " received " + m->getName() + " sent by " + socketB->getOwner()+"."+socketB->getName();
        HCIs::getInstance().log(HCI::INFO, msgReceived);
    } else {
        cout << "Unrecognized sender" << endl;
    }
}
