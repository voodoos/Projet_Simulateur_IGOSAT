﻿#include "Module.h"
#include "Memory.cpp"

//For convenience:
using namespace std;


Module::Module(string name, Params params)
: name(name), parameters(params), taskTimer(NOP)
{
}

Module::Module(string name, Memory<int> mem, Params params)
: name(name), memory(mem), parameters(params), taskTimer(NOP)
{
}


Module::~Module()
{
    
}

void Module::clock(int time) {

    //On récupère un message pas socket:
    this->getMessages();

    //On traite un peu:
    //Si fin attente tâche suivante:
    if (this->taskTimer == 0) {
        Message nextMsg = this->tasks.front();
        if (this->isMessageAllowed(nextMsg)){

            //Process est virtuelle pure, dépend de chaque module !
            this->process(nextMsg);

            this->tasks.pop();

            //On met à jour le timer:
            if (this->tasks.size() > 0){
                this->taskTimer = this->messagesAllowed[nextMsg.getName()];
            }
            else {
                this->taskTimer = NOP;
            }
        }
        else{
            /*! \todo Lever une exception */
            exit(EXIT_FAILURE);
        }
    }
    else {
        //Sinon, on dort:
        if(this->taskTimer != NOP){
            this->taskTimer--;
        }
    }
}


void Module::addSocket(Socket soc)
{
    //On ajoute le socket dans la hash_table, avec pour clé le nom du socket
    this->sockets[soc.getName()] = soc;
}

void Module::addMessage(Message msg, int processingTime)
{
    //Onvérifie l'absence de doublons:
    if (!this->isMessageAllowed(msg)){
        //On ajoute le message dans la hash_table, avec pour clé le nom du message
        this->messagesAllowed[msg.getName()] = processingTime;
    }
}



Socket& Module::getSocketByName(string sname)
{
    try {
        return this->sockets.at(sname);
    }
    catch (const out_of_range &e) {
        cout << "Out of range: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
    /*!
    *\todo Faire le retour d'un objet
    */
}

double Module::getParamValueByName(string pname)
{
    try {
        return this->parameters.at(pname);
    }
    catch (const out_of_range &e) {
        cout << "Out of range: " << e.what() << endl;
    }
    return 0;
}

void Module::setParamValueByName(string pname, double value){
    try {
        parameters.at(pname) = value;
    } catch (const out_of_range &e) {
        cout << "Out of range: " << e.what() << endl;
    }
}

bool Module::isMessageAllowed(Message m)
{
    try {
        this->messagesAllowed.at(m.getName());
    }
    catch (const out_of_range &e) {
        return false;
    }

    return true;
}

void Module::getMessages() {
    //On parcourt tous les sockets:
    for (auto kv : sockets) {
        //On regarde si la lecture est terminée:
        if (kv.second.getTimer() == 0) {
            //Si oui, on ajoute le message à la queue de traitement:
            this->tasks.push(kv.second.getFirstMessage());
        } else {
            kv.second.clock(0);
        }
    }
}