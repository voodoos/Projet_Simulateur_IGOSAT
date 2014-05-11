#include "File.h"
#include "Timer.h"

#include <sstream>


using namespace std;

File::File(string path, logLevel ll) : HCI(ll)
{
    //On s'enregistre dans le Timer:

    Timer::getInstance().add(this);
    file.open(path);
}


File::~File()
{
}


void File::logv(string mess, bool withTime) const {
    stringstream ss;
    if (withTime) {
        ss << Timer::getInstance().getCounter() << ": " << mess << endl ;
    }
    else {
        ss << mess << endl;
    }

    printStr(ss.str());
}


void File::addData(double data, int i) {
    //On ajoute la donnée dans le tableau:
    dataBuff.resize(i+1, nan("NaN"));
    dataBuff[i] = data;

}

void File::clock(int t) {
    if (dataBuff.size() > 0) {
        stringstream ss;
        ss << Timer::getInstance().getCounter() << " ";
        //On parcours le vecteur pour construire la ligne
        // TODO: Sûrement une exception à gérer...
        for (int i = 0; i < dataBuff.size(); i++) {
            if (!isnan(dataBuff[i]))
                ss << dataBuff[i] << " ";
            else ss << "NaN ";
        }

        //On écrit la ligne:
        printStr(ss.str());

        //On efface le buffer:
        dataBuff.clear();
    }
}

void File::printStr(string str) const {
    file << str << endl;
}