#include "Vol.h"
#include <iostream>
#include <fstream>
#include <sstream>

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

void Vol::chercherParVilleDepart(string ville)
{
	Destination destination;
	Vol vol;
	if (destination.chercherVilleDepart(ville) == ",") {
		cout << "Il n y a pas de vol arrivant dans cette ville" << "\n";
	}
	else {
		string ligne;
		string listNum = destination.chercherVilleDepart(ville);
		std::istringstream iss(listNum);
		std::string num;


		cout << "num   numVol   nbPlace     Destination              Date                Prix"<<"\n";

		while (std::getline(iss, num, ','))
		{

			numVol = vol.chercherParDestinationNum(num);

			std::istringstream iss2(numVol);
			std::string num2;

			while (std::getline(iss2, num2, ',')) {

				if (num2 != "") {
					chercherParNum(num2);
					cout << "\n";
				}

			}

		}

	}
}

void Vol::chercherParVilleArrivee(string ville)
{
	Destination destination;
	Vol vol;
	if (destination.chercherVilleArrive(ville) == ",") {
		cout << "Il n y a pas de vol arrivant dans cette ville" << "\n";
	}
	else {
		string ligne;
		string listNum = destination.chercherVilleArrive(ville);
		std::istringstream iss(listNum);
		std::string num;
		

		cout << "num   numVol   nbPlace     Destination                   Date                Prix" << "\n";

		while (std::getline(iss, num, ',') )
		{
			
			numVol= vol.chercherParDestinationNum(num);

			std::istringstream iss2(numVol);
			std::string num2;

			while (std::getline(iss2, num2, ',')) {
				if (num2 != "") {
					chercherParNum(num2);
					cout << "\n";
				}

			}

		}

	}
}


string Vol::chercherParDestinationNum(string num)
{
	ifstream fichier;
	fichier.open("Vol.txt", ios::in);

	string ligne;
	string lignePrecedente;
	string numero = ",";
	string numeroActuel = "1";

	ligne = "";
	int i = 0;


	while (fichier)    //Tant qu'on n'est pas a la fin
	{
		getline(fichier, ligne, ','); //On lit une ligne

		if (fichier) {
			while (ligne != "" && fichier)
			{
				
				if (i == 7) {
					i = 0;
					numeroActuel = ligne;

				}


				if (i == 3) {

					if (ligne == num) {
						numero.append(numeroActuel);
						numero.append(",");
					}
				}
				i++;
				lignePrecedente = ligne;
				getline(fichier, ligne, ',');
			}
		}
	}

	return numero;
}

void Vol::developperVol(string vol)
{
	//cout << vol;
	string ligne;
	Destination destination;
	Date date;
	std::istringstream iss(vol);
	std::string num;

	getline(iss, num, ',');
	cout << num << "     ";

	getline(iss, num, ',');
	cout << num<<"     ";

	getline(iss, num, ',');
	cout << num<<"     ";

	getline(iss, num, ',');
	destination.afficherDestination(num);

	getline(iss, num, ',');
	date.afficherDate(num);

	getline(iss, num, ',');
	cout << num;

}


void Vol::chercherParNum(string num)
{
	fstream out{ "Vol.txt" };

	ifstream fichier;
	Vol vol;
	string vole= "";
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

				if (i == 7 || i==0) {
					i = 0;

					if (num == ligne) {

						if (i == 0) {
							vole.append(num);
						}

						while (i!=6)
						{
							if (i != 0 && i!=6) {
								out << ',' << ligne;
								vole.append(",");
								vole.append(ligne);
							}

							getline(fichier, ligne, ',');
							i++;
							if (i == 6) {
								out << ",";
								vole.append(",");
								vol.developperVol(vole);
								
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
