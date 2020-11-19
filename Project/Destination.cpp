#include "Destination.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib> 

using namespace std;

Destination::Destination()
{

}

string Destination::crerDestination()
{
	

	fstream out{ "Destination.txt" };

	ifstream fichier;
	fichier.open("Destination.txt", ios::in);

	string ligne;
	int i=0;
	string numero;
	ligne = "";


	while (fichier)    //Tant qu'on n'est pas a la fin
	{

		getline(fichier, ligne,','); //On lit une ligne
		if (fichier) {
			while (ligne != "" && fichier)
			{
				out <<','<< ligne;

				if (i == 4) {
					i = 0;
				}

				if (i == 0) {
					cout << ligne;
					numero = ligne;
				}

				i++;
				getline(fichier, ligne, ',');
			}
		}

	}
	out << ",";

	cout << "Ville de depart : ";
	cin >> villeDepart;

	cout << "Ville d arrivee : ";
	cin >> villeArrive;

	this->villeDepart = villeDepart;
	this->villeArrive = villeArrive;

	int num = stoi(numero);
	num = num + 1;
	numero = to_string(num);
	string text = "";

	text.append("\n");
	text.append(",");
	text.append(numero);
	text.append(",");
	text.append(villeDepart);
	text.append(",");
	text.append(villeArrive);
	text.append(",");
	out << text;

	return numero;
}

void Destination::chercherVilleArrive()
{
	ifstream fichier;
	fichier.open("Destination.txt", ios::in);

	string ligne;
	string villeArrivee;
	string lignePrecedente;

	ligne = "";
	int i = 0;

	cout << "Entrez la ville arrive cherchee : ";
	cin >> villeArrivee;

	while (fichier)    //Tant qu'on n'est pas a la fin
	{
		getline(fichier, ligne, ','); //On lit une ligne

		if (fichier) {
			while (ligne != "" && fichier)
			{
				if (i == 4) {
					i = 0;
				}
				if (i == 2) {

					if (ligne == villeArrivee) {
						cout << "\n";
						cout << lignePrecedente << " ";
						cout << ligne << " \n";
					}
				}
				i++;
				lignePrecedente = ligne;
				getline(fichier, ligne, ',');
			}
		}
	}
}

void Destination::chercherVilleDepart()
{
	ifstream fichier;
	fichier.open("Destination.txt", ios::in);

	string ligne;
	string lignePrecedente;
	string villeDepart;

	ligne = "";
	int i = 0;

	cout << "Entrez la ville depart cherchee : ";
	cin >> villeDepart;

	while (fichier)    //Tant qu'on n'est pas a la fin
	{
		getline(fichier, ligne, ','); //On lit une ligne

		if (fichier) {
			while (ligne != "" && fichier)
			{
				if (i == 4) {
					i = 0;if (fichier) {
			while (ligne != "" && fichier)
			{
				if (i == 4) {
					i = 0;
				}
				if (i == 1) {
					if (ligne == villeDepart) {
						cout << "\n";
						cout << ligne << " ";
						i++;
						getline(fichier, ligne, ',');
						cout << ligne << " \n";
					}
				}
				i++;
				getline(fichier, ligne, ',');
			}
		}
				}
				if (i == 1) {
					if (ligne == villeDepart) {
						cout << "\n";
						cout << ligne << " ";
						i++;
						getline(fichier, ligne, ',');
						cout << ligne << " \n";
					}
				}
				i++;
				getline(fichier, ligne, ',');
			}
		}
	}
}

void Destination::afficherDestination()
{
	ifstream fichier;
	fichier.open("Destination.txt", ios::in);

	string ligne;
	ligne = "";

	while (fichier)    //Tant qu'on n'est pas a la fin
	{
		getline(fichier, ligne,','); //On lit une ligne

		if (fichier) {
			while (ligne!="" && fichier)
			{

				cout << ligne<<" ";
				
				getline(fichier, ligne, ',');

			}
		}
	}
	cout << "\n";

}

Destination::Destination(string villeDepart,string villeArrive) {
	this->villeArrive = villeArrive;
	this->villeDepart = villeDepart;
}



Destination::~Destination()
{
}

