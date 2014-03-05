#include "Timer.h"

using namespace std;
void Timer::addModule(Module *m){
    synchronizedModules.push_back(m);
}

void Timer::start(unsigned int c){
    for (counter=0; counter<c; ++counter) {
        for(vector<Module *>::iterator it = synchronizedModules.begin(); it != synchronizedModules.end(); ++it) {
            (*it)->clock(counter);
        }
    }
}

void Timer::stop(){
    
}