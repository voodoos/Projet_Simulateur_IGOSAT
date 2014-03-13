#include "Timer.h"

using namespace std;
void Timer::addModule(Module *m){
    synchronizedModules.push_back(m);
}

void Timer::addPhysics(Physics *p){
    synchronizedPhysics.push_back(p);
}

void Timer::start(unsigned int c){
    for (counter=0; counter<c; ++counter) {

        //On clock la physique:
        for (vector<ISynchronized *>::iterator it = synchronizedPhysics.begin(); it != synchronizedPhysics.end(); ++it) {
            (*it)->clock(counter);
        }

        //On clock les modules:
        for(vector<ISynchronized *>::iterator it = synchronizedModules.begin(); it != synchronizedModules.end(); ++it) {
            (*it)->clock(counter);
        }
    }
}

void Timer::stop(){
    
}