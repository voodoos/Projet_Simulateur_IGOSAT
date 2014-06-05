#include "HCI.h"

using namespace std;

HCI::HCI(logLevel ll) : logLev(ll)
{
}


HCI::~HCI()
{
}

void HCI::setLogLevel(logLevel ll) {
    logLev = ll;
}

void HCI::log(logLevel ll, string mess, bool withTime) const {
    if (ll <= logLev) {
        logv(mess, withTime);
    }
}