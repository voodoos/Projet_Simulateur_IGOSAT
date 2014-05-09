#include "Generators.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <direct.h>

#include "rapidxml.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml_utils.hpp"

using namespace std;


Generators::Generators()
{
}


void Generators::genModule() {
    bool isMacro = false;
    string isMacros = "a";
    string nomModule = "a";

    vector<pair<string, double>> params;
    vector<pair<string, double>> messs;
    vector<string> mods;
    string parami = "", modi = "", messi = "";

    cout << "**GENERATION DE MODULE**" << endl;
    cout << endl << "*INFOS GENERALES*" << endl;

    //Est-ce un macro module ?
    isMacro = getAnswer("Macromodule");

    //Quel est son nom ?
    nomModule = getString("Nom du module");

    //Des paramètres:
    cout << endl << "*PARAMETRES*" << endl;
    
    while (true) {
        cout << "Nom (vide si fin des parametres): ";
        getline(cin, parami);

        //Si fin de la lsite des paramètres, on break:
        if (parami.empty()) break;

        //Sinon on demande la valeur et on pushback:
        params.push_back(make_pair(parami, getDouble("Valeur (double)")));
    }

    //Messages:
    cout << endl << "*MESSAGES*" << endl;

    while (true) {
        cout << "Nom (vide si fin): ";
        getline(cin, messi);

        //Si fin de la lsite des modules, on break:
        if (messi.empty()) break;

        //Sinon on ajoute à la liste avec le temps qui va bien:
        messs.push_back(make_pair(modi, getInt("Temps de transmission (int) (0 = instant)")));
    }

    //Modules connectés:
    cout << endl << "*MODULES CONNECTES*" << endl;

    while (true) {
        cout << "Nom (vide si fin): ";
        getline(cin, modi);

        //Si fin de la lsite des modules, on break:
        if (modi.empty()) break;

        //Sinon on ajoute à la liste:
        mods.push_back(modi);
    }

    //If macro:
    if (isMacro) {
        nomModule = nomModule + "Module";
    }

    //On génère le code:
    genModuleFiles(isMacro, nomModule, params, messs, mods);
}

void Generators::genModuleFiles(bool macro, string nom,
    vector<pair<string, double>> params,
    vector<pair<string, double>> mess,
    vector<string> connexions){

    //Un fichier xml à générer, et deux fichiers source:
    _mkdir("GenCode");

    genModXmlFile(nom, params, mess, connexions);
    //genModCPPFile
}

void Generators::genModXmlFile(string nom,
    vector<pair<string, double>> params,
    vector<pair<string, double>> mess,
    vector<string> connexions) {

    //Creating xml doc:
    rapidxml::xml_document<> doc;

    //Noeud principal:
    rapidxml::xml_node<> *node = doc.allocate_node(rapidxml::node_element, "module", "");
    doc.append_node(node);
    rapidxml::xml_attribute<> *attr = doc.allocate_attribute("name", nom.c_str());
    node->append_attribute(attr);

    //Writing to file:
    ofstream file_stored("GenCode/"+nom+".xml");
    file_stored << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl;
    file_stored << doc;
    file_stored.close();
    doc.clear();
}

Generators::~Generators()
{
}

bool Generators::getAnswer(string mess) {
    bool repb = false;
    string rep = "";
    while (rep != "O" && rep != "n") {
        cout << mess << " (O/n) : ";
        getline(cin, rep);
    }
    if (rep == "O") repb = true;
    return repb;
}

string Generators::getString(string mess) {
    string rep = "";
    while (rep.empty()) {
        cout << mess << ": ";
        getline(cin, rep);
    }
    return rep;
}

double Generators::getDouble(string mess) {
    string rep;
    double repd;
    bool ok = false;
    
    while (!ok) {
        rep = getString(mess);
        try {
            repd = stod(rep);
            ok = true;
        }
        catch (invalid_argument) {}
    }

    return repd;
}

int Generators::getInt(string mess) {
    string rep;
    int repd;
    bool ok = false;

    while (!ok) {
        rep = getString(mess);
        try {
            repd = stoi(rep);
            ok = true;
        }
        catch (invalid_argument) {}
    }

    return repd;
}