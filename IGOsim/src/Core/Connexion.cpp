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

void Connexion::dispatch(std::shared_ptr<Message> m, Socket *s){
    std::string msgReceived("");
    if (s->getName() == socketA->getName()) {
        socketB->receive(m);
        msgReceived = "Socket "+socketB->getName() + " received " + m->getName() + " sent by " + socketA->getName();
        CLI::getInstance().log(CLI::INFO, msgReceived);
        /*cout << "Socket " << socketB->getName() << " received " << m->getName() << " sent by " << socketA->getName() << endl;*/
    } else if(s->getName() == socketB->getName()) {
        socketA->receive(m);
        msgReceived = "Socket "+socketA->getName() + " received " + m->getName() + " sent by " + socketB->getName();
        CLI::getInstance().log(CLI::INFO, msgReceived);
        /*cout << "Socket " << socketA->getName() << " received " << m->getName() << " sent by " << socketB->getName() << endl;*/
    } else {
        cout << "Unrecognized sender" << endl;
    }
}
