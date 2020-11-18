#include "Passager.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>


void Passager::creerPassager()
{
	fstream out{ "Passager.txt" };

	


	ifstream fichier;
	fichier.open("Passager.txt", ios::in);

	string ligne;
	ligne = "";
	int i = 0;
	string numero;

	while (fichier)    //Tant qu'on n'est pas a la fin
	{

		getline(fichier, ligne,','); //On lit une ligne
		if (fichier) {
			while (ligne != "" && fichier)
			{
				out << ',' << ligne;

				if (i == 7) {
					i = 0;
				}

				if (i == 0) {
					numero = ligne;
				}

				i++;
				getline(fichier, ligne, ',');
			}
		}

	}

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

	int num = stoi(numero);
	num = num + 1;
	numero = to_string(num);

	string text = "";
	text.append(",");
	text.append("\n");
	text.append(",");
	text.append(numero);
	text.append(",");
	text.append(nom);
	text.append(",");
	text.append(prenom);
	text.append(",");
	text.append(to_string(age));
	text.append(",");
	text.append(titre);
	text.append(",");
	text.append(numPasseport);
	text.append(",");

	out << text;
}

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

void Passager::afficherPassager()
{
	ifstream fichier;
	fichier.open("Passager.txt", ios::in);

	string ligne;
	ligne = "";

	while (fichier)    //Tant qu'on n'est pas a la fin
	{
		getline(fichier, ligne, ','); //On lit une ligne

		if (fichier) {
			while (ligne != "" && fichier)
			{

				cout << ligne << " ";

				getline(fichier, ligne, ',');

			}
		}
	}
	cout << "\n";
}

