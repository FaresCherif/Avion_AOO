#include "Vol.h"
#include <iostream>

using namespace std;


Vol::Vol(string numVol, int nbPlaceMax, Destination destination, Date date, float prix)
{
	this->numVol = numVol;
	this->nbPlaceMax = nbPlaceMax;
	this->destination = destination;
	this->date = date;
	this->prix = prix;
}

Vol::Vol() {
	
}

Vol::~Vol()
{
}
