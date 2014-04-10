// IGOgen.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Generators.h"

//For convenience:
using namespace std;


int main(int argc, char *argv[])
{
    Generators::genModule();
    cin.ignore();
	return 0;
}

