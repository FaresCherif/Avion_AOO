#pragma once
#include <string>
#include <vector>
#include <iostream>


using namespace std;

class Client
{
	string nom;
	string prenom;
	int age;
	enum string { Mme, M, Mlle };
	string NumPasseport;

public:
	void reserver();
	void confirmer();
	void annuler();
	void afficherListeVol();
	void verifierVol();
	void verifierReservation();

};