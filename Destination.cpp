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

	Destination destination;
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

	if (destination.rechercherDestination(villeDepart, villeArrive) == "")
	{
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
	else {
		return destination.rechercherDestination(villeDepart, villeArrive);
	}
}

string Destination::rechercherDestination(string villeDepart,string villeArrive) {
	string numero = "";
	string numeroEnCours = "";

	fstream out{ "Destination.txt" };

	ifstream fichier;
	fichier.open("Destination.txt", ios::in);
	string ligne;
	int i = 0;


	while (fichier)    //Tant qu'on n'est pas a la fin
	{

		getline(fichier, ligne, ','); //On lit une ligne
		if (fichier) {
			while (ligne != "" && fichier)
			{
				out << ',' << ligne;

				if (i == 4) {
					i = 0;
					numeroEnCours = ligne;
				}

				if (i == 1) {
					if (villeDepart == ligne) {
							
						getline(fichier, ligne, ',');
						i++;
						out << ',' << ligne;
							
						if (villeArrive == ligne) {

							numero = numeroEnCours;
						}
						
					}
				}

				i++;
				getline(fichier, ligne, ',');
			}
		}

	}

	cout << numero;
	return numero;
}


string Destination::chercherVilleArrive(string villeArrivee)
{
	ifstream fichier;
	fichier.open("Destination.txt", ios::in);

	string ligne;
	string lignePrecedente;
	string numero=",";
	string numeroActuel="1";

	ligne = "";
	int i = 0;

	while (fichier)    //Tant qu'on n'est pas a la fin
	{
		getline(fichier, ligne, ','); //On lit une ligne

		if (fichier) {
			while (ligne != "" && fichier)
			{
				if (i == 4) {
					i = 0;
					numeroActuel = ligne;
				}
				if (i == 1) {
					
				}

				if (i == 2) {
					if (ligne == villeArrivee) {

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

string Destination::chercherVilleDepart(string villeDepart)
{
	ifstream fichier;
	fichier.open("Destination.txt", ios::in);

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
				if (i == 4) {
					i = 0;
					numeroActuel = ligne;
				}

				if (i == 1) {
					if (ligne == villeDepart) {
						i++;
						getline(fichier, ligne, ',');
						numero.append(numeroActuel);
						numero.append(",");

					}
				}
				i++;
				getline(fichier, ligne, ',');
			}
		}
	}
	return numero;
	
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

void Destination::afficherDestination(string num)
{
	ifstream fichier;
	fichier.open("Destination.txt", ios::in);

	string ligne;
	string lignePrecedente;


	ligne = "";
	int i = 0;

	while (fichier)    //Tant qu'on n'est pas a la fin
	{
		getline(fichier, ligne, ','); //On lit une ligne

		if (fichier) {

			while (ligne != "" && fichier)
			{
				if (i == 4) {
					i = 0;
				}

				if (i == 0) {
					if (ligne == num) {
					
						getline(fichier, ligne, ',');
						cout << ligne<<"--";
						getline(fichier, ligne, ',');
						cout << ligne;
					}
				}
				i++;
				getline(fichier, ligne, ',');
			}
		}
	}
}

Destination::Destination(string villeDepart,string villeArrive) {
	this->villeArrive = villeArrive;
	this->villeDepart = villeDepart;
}



Destination::~Destination()
{
}

