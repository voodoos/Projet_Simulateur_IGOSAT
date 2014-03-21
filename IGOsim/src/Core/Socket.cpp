#include "Socket.h"

//For convenience:
using namespace std;


Socket::Socket(std::string name) : name(name), timer(-1)
{
}

Socket::Socket(const Socket &s){
    name = s.name;
    messageQueue = s.messageQueue;
    connexion = s.connexion;
    timer = s.timer;

    //cout << "copie" << s.name<< endl;
}


Socket::~Socket()
{
}


void Socket::setConnexion(Connexion &c){
    connexion = &c;
}

void Socket::receive(Message *m){
    //On ajoute le message à la queue:
    messageQueue.push(m);

    //Si la queue était vide:
    if (messageQueue.size() == 1) {
        //On règle le timer:
        timer = m->getTransmissionTime();
    }
}

void Socket::send(Message *m){
    /*! \todo Et si connexion est null ? */
    connexion->dispatch(m, this);
}

void Socket::clock(int time){
    if (timer >= 0) {
        timer--;
    }
}

std::string Socket::getName(){
    return name;
}

bool Socket::hasMessage(){
    return !messageQueue.empty();
}

Message *Socket::getFirstMessage(){
    //On vérifie qu'il y a effectivement des messages:
    if (messageQueue.size() > 0){

        //On récupère et supprime le premier message:
        Message *m = messageQueue.front();
        //Message m(*messageQueue.front());
        messageQueue.pop();

        //Et on met règle le timer pour le message suivant, ou à zéro si c'est fini:
        if (messageQueue.size() > 0) {
            timer = messageQueue.front()->getTransmissionTime();
        }
        else {
            timer = -1;
        }

        return m;
    }
    else {
        /*! \todo Lever une exception */
        exit(EXIT_FAILURE);
    }
}

int Socket::getTimer() const {
    return timer;
}