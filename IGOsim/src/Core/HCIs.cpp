#include "HCIs.h"

#include "CLI.h"
#include "File.h"

using namespace std;

void HCIs::setLog(HCI::logLevel ll)
{    
    if (!loggerSet) {
        logger = new CLI(ll);
        loggerSet = true;
    }
}

void HCIs::setLog(string file, HCI::logLevel ll)
{
    if (!loggerSet) {
        logger = new File(file, ll);
        loggerSet = true;
    }
}

void HCIs::log(HCI::logLevel ll, std::string mess, bool withTime) {
    //Si aucun logger configuré, ligne de commande par défaut:
    if (!loggerSet) setLog();

    //On log:
    logger->log(ll, mess, withTime);
}

HCIs::~HCIs()
{
    delete(logger);
}
