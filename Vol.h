#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Destination.h"
#include "Date.h"


using namespace std;

class Vol
{
	string numVol;
	int nbPlaceMax;
	Destination destination;
	Date date;
	float prix;

public:
	Vol(string, int, Destination, Date,float);
	Vol();
	void creerVol();
	void afficherVol();
	void chercherParVilleDepart(string);
	void chercherParVilleArrivee(string);
	void chercherParNum(string num);
	string chercherParDestinationNum(string num);
	void developperVol(string vol);
	~Vol();
};

