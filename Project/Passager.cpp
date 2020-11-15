#include "Passager.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>


void Passager::reserver()
{

}

void Passager::confirmer()
{

}

void Passager::annuler()
{

}

void Passager::afficherListeVol()
{

}

void Passager::verifierVol()
{

}


void Passager::verifierReservation()
{

}


Passager::Passager() {
	std::ofstream out{ "Passager.txt" };

	cout << "Entrez le nom : ";
	cin >> nom;
	cout << "Entrez le prenom : ";
	cin >> prenom;
	cout << "Entrez l age";
	cin >> age;
	cout << "Entrez le titre (Mme/M/Mlle) : ";
	cin >> titre;
	cout << "Entrez le numDePasseport : ";
	cin >> numPasseport;

	this->nom = nom;
	this->prenom = prenom;
	this->age = age;
	this->titre = titre;
	this->numPasseport = numPasseport;

	out << nom << "," << prenom << "," << age << "," << titre << "," << numPasseport << "\n";

	out.close();
}

Passager::Passager(string nom,string prenom,int age,string titre,string numPasseport) {

	std::ofstream out{ "Passager.txt"};

	this->nom = nom;
	this->prenom = prenom;
	this->age = age;
	this->titre = titre;
	this->numPasseport = numPasseport;

	out << nom<<","<<prenom<<","<<age<<","<<titre<<","<<numPasseport<<"\n";

}