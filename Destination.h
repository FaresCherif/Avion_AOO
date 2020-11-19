#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Destination
{
	string villeDepart;
	string villeArrive;

public:
	Destination();
	string crerDestination();
	string rechercherDestination(string,string);
	string chercherVilleArrive(string);
	string chercherVilleDepart(string);
	void afficherDestination();
	void afficherDestination(string);
	Destination(string,string);
	~Destination();
};

