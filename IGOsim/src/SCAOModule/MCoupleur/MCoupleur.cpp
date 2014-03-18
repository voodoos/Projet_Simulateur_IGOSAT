#include "MCoupleur.h"

using namespace std;

MCoupleur::MCoupleur(Params params) : Module("MCoupleur", params)
{
    //Commandes acceptée par le magnetocoupleur
    addMessage(Message("setVoltage", "", 5), 5);
    addMessage(Message("unsetVoltage", "", 5), 5);
    addMessage(Message("getVoltage", "", 5),5);
    //Connecteur
    addSocket(Socket("out"));
    
}

void MCoupleur::process(Message m)
{
    if(m.getName() == "setVoltage"){
        setParamValueByName("voltage", 1);
    }
    if(m.getName() == "unsetVoltage"){
        setParamValueByName("voltage", 0);
    }
    if(m.getName()=="getVoltage"){
        if (getParamValueByName("voltage")) {
            getSocketByName("out")->send(Message("voltage", "set"));
        }else{
            getSocketByName("out")->send(Message("voltage", "unset"));
        }
    }
}