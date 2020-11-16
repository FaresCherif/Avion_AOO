#include "Date.h"
#include <fstream>



Date::Date()
{
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

	string texteDate="";
	string texteHeure="";

	texteDate.append(jour);	texteDate.append("/");	texteDate.append(mois);	texteDate.append("/"); texteDate.append(annee); texteDate.append(",");
	texteHeure.append(heuree); texteHeure.append(":"); texteHeure.append(minute);
	
	this->date = texteDate;
	this->heure = texteHeure;

	fstream out{ "Date.txt" };

	ifstream fichier;
	fichier.open("Date.txt", ios::in);

	string ligne;
	ligne = "";


	while (fichier)    //Tant qu'on n'est pas a la fin
	{

		getline(fichier, ligne); //On lit une ligne
		if (fichier) {
			out << ligne << "\n";
		}

	}

	out << texteDate; out << texteHeure;
}

Date::Date(string date,string heure)
{
	this->date = date;
	this->heure = heure;
}

Date::~Date()
{

}
