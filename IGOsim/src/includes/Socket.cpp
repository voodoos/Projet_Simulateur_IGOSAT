#include "Socket.h"


Socket::Socket(std::string name)
{
    this->name = name;
}


Socket::~Socket()
{
    
}


void Socket::setConnexion(Connexion c){
    this->connexion = &c;
}

void Socket::receive(Message m){
    this->messageQueue.push(m);
}

void Socket::send(Message m){
    this->connexion->dispatch(m, this);
}

std::string Socket::getName(){
    return this->name;
}

bool Socket::hasMessage(){
    return !this->messageQueue.empty();
}

Message Socket::getLastMessage(){
    Message m(this->messageQueue.front());
    this->messageQueue.pop();
    return m;
}