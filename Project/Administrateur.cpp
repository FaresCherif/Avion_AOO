#include "Administrateur.h"
#include <string>
#include <iostream>

using namespace std;


void Administrateur::seConnecter()
{
}


void Administrateur::ajouterUnVol()
{

}

void Administrateur::ajouterUnPassager()
{
}


void Administrateur::ajouterUneReservation()
{
}

void Administrateur::ajouterUneDestination()
{
}

void Administrateur::modifierHeureDeVol()
{
}

void Administrateur::modifierDateVol()
{
}

void Administrateur::afficherListeVol()
{
}

void Administrateur::verifierExistenceVol()
{
}

void Administrateur::afficherListePassagerVol()
{
}

Administrateur::Administrateur(string identifiant, string motDePasse) {
	this->identifiant = identifiant;
	this->motDePasse = motDePasse;
}

Administrateur::Administrateur() {
	cout << "Identifiant : ";
	cin >> identifiant;
	cout << "Mot de Passe : ";
	string mdp;
	cin >> mdp;
	this->identifiant = identifiant;
	this->motDePasse = mdp;

}