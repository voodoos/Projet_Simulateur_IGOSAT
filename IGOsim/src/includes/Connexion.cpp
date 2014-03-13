#include "Connexion.h"
#include "Socket.h"

#include "CLI.h"
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

void Connexion::dispatch(Message m, Socket *s){
    if (s->getName() == socketA->getName()) {
        socketB->receive(m);
        CLI::getInstance().log(CLI::ERROR, "TOTO3");
        cout << "Socket " << socketB->getName() << " received " << m.getName() << "(" << m.getPayload() << ") sent by " << socketA->getName() << endl;
    } else if(s->getName() == socketB->getName()) {
        socketA->receive(m);
        cout << "Socket " << socketA->getName() << " received " << m.getName() << "(" << m.getPayload() << ") sent by " << socketB->getName() << endl;
    } else {
        cout << "Unrecognized sender" << endl;
    }
}
