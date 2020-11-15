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
	fstream out{ "Passager.txt" };

	cout << "Entrez le nom : ";
	cin >> nom;
	cout << "Entrez le prenom : ";
	cin >> prenom;
	cout << "Entrez l age : ";
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

	string text = nom;
	text.append(",");
	text.append(prenom);
	text.append(",");
	text.append(to_string(age));
	text.append(",");
	text.append(titre);
	text.append(",");
	text.append(numPasseport);

	ifstream fichier;
	fichier.open("Passager.txt", ios::in);

	string ligne;
	ligne = "";


	while (fichier)    //Tant qu'on n'est pas a la fin
	{

		getline(fichier, ligne); //On lit une ligne
		if (fichier) {
			out << ligne << "\n";
		}

	}

	out << text;

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