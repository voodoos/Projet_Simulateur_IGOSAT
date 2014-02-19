#include "Memory.h"


template<class T>
Memory<T>::Memory()
{
}

template<class T>
Memory<T>::Memory(std::unordered_map<std::string, T> cells)
{
    this->cells = cells;
}

template<class T>
unsigned int Memory<T>::getSize(){
    return this->cells.size;
}

template <class T>
int Memory<T>::setValueForKey(std::string key, T value){
    this->cells[key] = value;
}

template<class T>
Memory<T>::~Memory()
{
    cells.clear();
}

