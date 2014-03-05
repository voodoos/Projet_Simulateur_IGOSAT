#include "Socket.h"

//For convenience:
using namespace std;


Socket::Socket(std::string name) : name(name), timer(-1)
{
}


Socket::~Socket()
{
}


void Socket::setConnexion(Connexion c){
    this->connexion = &c;
}

void Socket::receive(Message m){
    //On ajoute le message à la queue:
    this->messageQueue.push(m);

    //Si la queue était vide:
    if (messageQueue.size() == 1) {
        //On règle le timer:
        this->timer = m.getProcessingTime();
    }
}

void Socket::send(Message m){
    this->connexion->dispatch(m, this);
}

void Socket::clock(int time){
    if (this->timer > 0) {
        timer--;
    }
}

std::string Socket::getName(){
    return this->name;
}

bool Socket::hasMessage(){
    return !this->messageQueue.empty();
}

Message Socket::getFirstMessage(){
    //On vérifie qu'il y a effectivement des messages:
    if (this->messageQueue.size() > 0){

        //On récupère et supprime le premier message:
        Message m(this->messageQueue.front());
        this->messageQueue.pop();

        //Et on met règle le timer pour le message suivant, ou à zéro si c'est fini:
        if (this->messageQueue.size() > 0) {
            this->timer = this->messageQueue.front().getProcessingTime();
        }
        else {
            this->timer = -1;
        }

        return m;
    }
    else {
        /*! \todo Lever une exception */
        exit(EXIT_FAILURE);
    }
}

int Socket::getTimer() const {
    return this->timer;
}