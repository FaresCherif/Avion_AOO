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
	void crerDestination();
	void chercherVilleArrive();
	void chercherVilleDepart();
	void afficherDestination();
	Destination(string,string);
	~Destination();
};

