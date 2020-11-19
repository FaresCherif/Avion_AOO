#include "Date.h"
#include <fstream>



Date::Date()
{
	
}

Date::Date(string date,string heure)
{
	this->date = date;
	this->heure = heure;
}

string Date::creerDate()
{
	int i = 0;
	string numero;

	fstream out{ "Date.txt" };

	ifstream fichier;
	fichier.open("Date.txt", ios::in);

	cout << "Jour : ";
	string jour;
	cin >> jour;
	cout << "Mois : ";
	string mois;
	cin >> mois;
	cout << "Annee : ";
	string annee;
	cin >> annee;
	cout << "Heure : ";
	string heuree;
	cin >> heuree;
	cout << "Minute : ";
	string minute;
	cin >> minute;

	string texteDate = "";
	string texteHeure = "";

	texteDate.append(jour);	texteDate.append("/");	texteDate.append(mois);	texteDate.append("/"); texteDate.append(annee); texteDate.append(",");
	texteHeure.append(heuree); texteHeure.append(":"); texteHeure.append(minute);

	this->date = texteDate;
	this->heure = texteHeure;


	string ligne;
	ligne = "";


	while (fichier)    //Tant qu'on n'est pas a la fin
	{

		getline(fichier, ligne,','); //On lit une ligne

		if (fichier) {
			if (i == 4) {
				i = 0;
			}
			if (i == 1) {
				numero = ligne;
				cout << numero;
				cout << "numero";
			}
			i++;
			out << ligne;
			out << ',';
		}

	}

	int num = stoi(numero);
	num = num + 1;
	numero = to_string(num);

	out <<"\n"<<","<<numero<<','<< texteDate;out << texteHeure <<",";

	return numero;
}

void Date::afficherDate()
{
	ifstream fichier;
	fichier.open("Date.txt", ios::in);

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

Date::~Date()
{

}


