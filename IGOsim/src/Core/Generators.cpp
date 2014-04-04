#include "Generators.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;


Generators::Generators()
{
}


void Generators::genModule() {
    bool isMacro = false;
    string isMacros = "a";
    string nomModule = "a";

    vector<pair<string, double>> params;
    string parami = "";

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
        cin >> parami;

        //Si fin de la lsite des paramètres, on break:
        if (parami.empty()) break;

        //Sinon on demande la valeur et on pushback:
        params.push_back(make_pair(parami, getDouble("Valeur (double)")));

    }

    


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