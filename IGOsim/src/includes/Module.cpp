#include "Module.h"
#include "Memory.cpp"

//For convenience:
using namespace std;


Module::Module(string name, Params params)
: name(name), parameters(params)
{
}

Module::Module(string name, Memory<int> mem, Params params)
: name(name), memory(mem), parameters(params)
{
}


Module::~Module()
{
    
}


void Module::clock(int time) {
    //On récupère un message pas socket:
    getMessages();

    //On traite un peu:
    process();
}


void Module::addSocket(Socket soc)
{
    //On ajoute le socket dans la hash_table, avec pour clé le nom du socket
    this->sockets[soc.getName()] = soc;
}

void Module::addMessage(Message msg)
{
    //On ajoute le socket dans la hash_table, avec pour clé le nom du message
    this->messagesAllowed[msg.getName()] = msg;
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