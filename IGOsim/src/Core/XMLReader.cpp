#include "XMLReader.h"

#include <iostream>

#include "CLI.h"

#include "RapidXML\rapidxml.hpp"
#include "RapidXML\rapidxml_utils.hpp"

using namespace std;

//Initialisation variable statique:
string XMLReader::basePath = "config/";

XMLReader::~XMLReader() {

}


unordered_map<string, double> XMLReader::readParams(string confPath) {

    //On tente d'ouvrir le fichier:
    cout << "Reading from: " << basePath + confPath;

    rapidxml::xml_document<> doc;

    try {
        rapidxml::file<char> xmlFile((basePath+confPath).c_str());
        doc.parse<0>(xmlFile.data());
        cout << "Name of my first node is: " << doc.first_node()->name() << "\n";
        return  unordered_map<string, double>();
    }
    catch (const runtime_error &error){
        //Exception non bloquante:
        CLI::getInstance().log(CLI::WARNING, "Impossible de lire le fichier de configuration "+basePath+confPath+"\n"+error.what());
        throw;
    }
    catch (rapidxml::parse_error &e) {
        CLI::getInstance().log(CLI::ERROR, "Erreur de syntaxe dans le fichier de configuration " + basePath + confPath);
        //Exception bloquante !
    }
}


void XMLReader::setPath(string p) {
    basePath = p;
}

string XMLReader::getPath() {
    return basePath;
}