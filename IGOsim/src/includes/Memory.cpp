#include "Memory.h"


template<class T>
Memory<T>::Memory()
{
}

template<class T>
Memory<T>::Memory(std::unordered_map<std::string, T> _cells)
{
    cells = _cells;
}

template<class T>
unsigned int Memory<T>::getSize(){
    return cells.size;
}

template <class T>
int Memory<T>::setValueForKey(std::string key, T value){
    cells[key] = value;
}

template<class T>
Memory<T>::~Memory()
{
    cells.clear();
}

