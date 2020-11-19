#include "Vol.h"
#include <iostream>
#include <fstream>

using namespace std;


Vol::Vol(string numVol, int nbPlaceMax, Destination destination, Date date, float prix)
{
	this->numVol = numVol;
	this->nbPlaceMax = nbPlaceMax;
	this->destination = destination;
	this->date = date;
	this->prix = prix;
}

Vol::Vol() {
	
}

void Vol::creerVol()
{
	fstream out{ "Vol.txt" };

	ifstream fichier;
	fichier.open("Vol.txt", ios::in);

	string ligne;
	ligne = "";
	int i = 0;
	string numero;

	while (fichier)    //Tant qu'on n'est pas a la fin
	{

		getline(fichier, ligne, ','); //On lit une ligne
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

	Destination destination;
	string numDestination;
	Date date;
	string numDate;
	string prix;
	string placeMax;

	cout << "Entrez le numero de vol : ";
	cin >> numVol;
	cout << "Entrez le nombre de place : ";
	cin >> nbPlaceMax;
	numDestination = destination.crerDestination();
	numDate = date.creerDate();
	cout << "Entrez le prix du vol : ";
	cin >> prix;

	int num = stoi(numero);
	num = num + 1;
	numero = to_string(num);
	placeMax = to_string(nbPlaceMax);

	cout << numDestination;
	string text = "";
	text.append(",");
	text.append("\n");
	text.append(",");
	text.append(numero);
	text.append(",");
	text.append(numVol);
	text.append(",");
	text.append(placeMax);
	text.append(",");
	text.append(numDestination);
	text.append(",");
	text.append(numDate);
	text.append(",");
	text.append(prix);
	text.append(",");

	out << text;
}

void Vol::afficherVol()
{
	ifstream fichier;
	fichier.open("Vol.txt", ios::in);

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

void Vol::chercherParNum(string num)
{
	fstream out{ "Vol.txt" };

	ifstream fichier;
	fichier.open("Vol.txt", ios::in);

	string ligne;
	ligne = "";
	int i = 0;
	string numero;

	while (fichier)    //Tant qu'on n'est pas a la fin
	{

		getline(fichier, ligne, ','); //On lit une ligne
		if (fichier) {
			while (ligne != "" && fichier)
			{
				out << ',' << ligne;

				if (i == 7) {
					i = 0;
					if (num == ligne) {
						while (i!=6)
						{
							if (i != 0) {
								out << ',' << ligne;
							}
							cout << ligne << " ";

							getline(fichier, ligne, ',');
							i++;
							if (i == 6) {
								out << ",";
							}
							if (i == 6 && fichier) {
								out << "\n";
							}
						}
					}
				}

				if (i == 0) {
					numero = ligne;
				}

				i++;
				getline(fichier, ligne, ',');
			}
		}

	}
}

Vol::~Vol()
{
}
