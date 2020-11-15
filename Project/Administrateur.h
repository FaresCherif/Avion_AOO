#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Administrateur
{
	string identifiant;
	string motDePasse;

public:
	Administrateur();
	Administrateur(string,string);

	void seConnecter();
	void ajouterUnVol();
	void ajouterUnPassager();
	void ajouterUneReservation();
	void ajouterUneDestination();
	void modifierHeureDeVol();
	void modifierDateVol();
	void afficherListeVol();
	void verifierExistenceVol();
	void afficherListePassagerVol();
};

