#pragma once
#include <string>
#include <vector>
#include <iostream>


using namespace std;

class Passager
{
	string nom;
	string prenom;
	int age;
	string titre;
	string numPasseport;

public:
	Passager();
	Passager(string, string, int, string ,string);
	void afficherPassager();
	void creerPassager();
	void reserver();
	void confirmer();
	void annuler();
	void afficherListeVol();
	void verifierVol();
	void verifierReservation();

};