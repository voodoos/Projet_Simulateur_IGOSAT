#include "XMLReader.h"

#include <iostream>

#include "HCIs.h"
#include "HCI.h"

#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"

using namespace std;

//Initialisation variable statique avec valeur par défaut:
string XMLReader::basePath = "config/";

XMLReader::~XMLReader() {

}


unordered_map<string, double> XMLReader::readParams(string confPath) {

    //On tente d'ouvrir le fichier:

    try { 
        unordered_map<string, double> ret;
        rapidxml::xml_document<> doc;

        //On ouvre:
        rapidxml::file<> xmlFile((basePath+confPath).c_str());
        doc.parse<0>(xmlFile.data());

        //On récupère le noeud principal des parametres:
        if (doc.first_node("module") != 0 && doc.first_node("module")->first_node("parameters") != 0) {
            rapidxml::xml_node<> * root_node = doc.first_node("module")->first_node("parameters");

            //On parcours les paramètres:
            for (rapidxml::xml_node<> * param = root_node->first_node("parameter"); param; param = param->next_sibling())
            {
                if (param->first_attribute("name") != 0 && param->first_node("value") != 0) {
                    string name = param->first_attribute("name")->value();
                    double value = atof(param->first_node("value")->value());
                    ret[name] = value;
                }
                else {
                    //Erreur de parsing:
                    throw rapidxml::parse_error("Name or value of parameter undefined", nullptr);
                }
            }
        }
        else {
            //Erreur de parsing:
            throw rapidxml::parse_error("Module or parameters undefined", nullptr);
        }

        return  ret;
    }
    catch (const runtime_error &error){
        //Erreur à l'ouverture du fichier:
        HCIs::getInstance().log(HCI::WARNING, "Impossible de lire le fichier de configuration "+basePath+confPath+"\n"+error.what(), false);
        throw;
    }
    catch (rapidxml::parse_error &e) {
        //Erreur de parsing:
        HCIs::getInstance().log(HCI::ERROR, "Erreur de syntaxe dans le fichier de configuration " + basePath + confPath + ":\n " + e.what(), false);
        //Erreur bidon
        throw 0;
    }
}

unordered_map<string, int> XMLReader::readMessages(string confPath) {

    //On tente d'ouvrir le fichier:

    try {
        unordered_map<string, int> ret;
        rapidxml::xml_document<> doc;

        //On ouvre:
        rapidxml::file<> xmlFile((basePath + confPath).c_str());
        doc.parse<0>(xmlFile.data());

        //On récupère le noeud principal des parametres:
        if (doc.first_node("module") != 0 && doc.first_node("module")->first_node("messages") != 0) {
            rapidxml::xml_node<> * root_node = doc.first_node("module")->first_node("messages");

            //On parcours les paramètres:
            for (rapidxml::xml_node<> * param = root_node->first_node("message"); param; param = param->next_sibling())
            {
                if (param->first_attribute("name") != 0 && param->first_node("time") != 0) {
                    string name = param->first_attribute("name")->value();
                    int value = atoi(param->first_node("time")->value());
                    ret[name] = value;
                }
                else {
                    //Erreur de parsing:
                    throw rapidxml::parse_error("Name or value of parameter undefined", nullptr);
                }
            }
        }
        else {
            //Erreur de parsing:
            throw rapidxml::parse_error("Module or parameters undefined", nullptr);
        }

        return  ret;
    }
    catch (const runtime_error &error){
        //Erreur à l'ouverture du fichier:
        HCIs::getInstance().log(HCI::WARNING, "Impossible de lire le fichier de configuration " + basePath + confPath + "\n" + error.what(), false);
        throw;
    }
    catch (rapidxml::parse_error &e) {
        //Erreur de parsing:
        HCIs::getInstance().log(HCI::ERROR, "Erreur de syntaxe dans le fichier de configuration " + basePath + confPath + ":\n " + e.what(), false);
        //Erreur bidon
        throw 0;
    }
}

vector<string> XMLReader::readSockets(string confPath){
    //On tente d'ouvrir le fichier:
    
    try {
        vector<string> ret;
        rapidxml::xml_document<> doc;
        
        //On ouvre:
        rapidxml::file<> xmlFile((basePath + confPath).c_str());
        doc.parse<0>(xmlFile.data());
        
        //On récupère le noeud principal des parametres:
        if (doc.first_node("module") != 0 && doc.first_node("module")->first_node("sockets") != 0) {
            rapidxml::xml_node<> * root_node = doc.first_node("module")->first_node("sockets");
            
            //On parcours les paramètres:
            for (rapidxml::xml_node<> * param = root_node->first_node("socket"); param; param = param->next_sibling())
            {
                if (param->first_attribute("name") != 0) {
                    string name = param->first_attribute("name")->value();
                    ret.insert(ret.end(), name);
                }
                else {
                    //Erreur de parsing:
                    throw rapidxml::parse_error("Name or value of parameter undefined", nullptr);
                }
            }
        }
        else {
            //Erreur de parsing:
            throw rapidxml::parse_error("Module or parameters undefined", nullptr);
        }
        
        return  ret;
    }
    catch (const runtime_error &error){
        //Erreur à l'ouverture du fichier:
        HCIs::getInstance().log(HCI::WARNING, "Impossible de lire le fichier de configuration " + basePath + confPath + "\n" + error.what(), false);
        throw;
    }
    catch (rapidxml::parse_error &e) {
        //Erreur de parsing:
        HCIs::getInstance().log(HCI::ERROR, "Erreur de syntaxe dans le fichier de configuration " + basePath + confPath + ":\n " + e.what(), false);
        //Erreur bidon
        throw 0;
    }
}

void XMLReader::setPath(string p) {
    basePath = p;
}

string XMLReader::getPath() {
    return basePath;
}