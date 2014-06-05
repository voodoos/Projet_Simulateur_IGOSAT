#include "CLI.h"
#include "Timer.h"

using namespace std;

CLI::CLI(logLevel ll) : HCI(ll) {}

CLI::~CLI()
{
}

void CLI::logv(string mess, bool withTime) const {
    if (withTime) {
        cout << Timer::getInstance().getCounter() << ": " << mess << endl;
    }
    else {
        cout << mess << endl;
    }
}