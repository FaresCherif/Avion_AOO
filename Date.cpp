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

	texteDate.append(jour);	texteDate.append("/");	texteDate.append(mois);	texteDate.append("/"); texteDate.append(annee); 
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

			}
			i++;
			out << ligne;
			out << ',';
		}

	}

	Date date;


	if (date.chercherDate(texteDate, texteHeure) == "") {
		texteDate.append(",");
		int num = stoi(numero);
		num = num + 1;
		numero = to_string(num);

		out << "\n" << "," << numero << ',' << texteDate; out << texteHeure << ",";

		return numero;
	}

	else {
		return date.chercherDate(texteDate, texteHeure);
	}
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

string Date::chercherDate(string date, string heure)
{
	string numero = "";
	string numeroEnCours = "";

	fstream out{ "Date.txt" };

	ifstream fichier;
	fichier.open("Date.txt", ios::in);
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
					if (date == ligne) {
						cout << ligne;
						getline(fichier, ligne, ',');
						i++;
						out << ',' << ligne;

						if (heure == ligne) {
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


	return numero;
}

Date::~Date()
{

}

void Date::afficherDate(string num)
{
	ifstream fichier;
	fichier.open("Date.txt", ios::in);

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
						cout << "         ";
						getline(fichier, ligne, ',');
						cout << ligne << " ";
						getline(fichier, ligne, ',');
						cout << ligne << "         ";
					}
				}
				i++;
				getline(fichier, ligne, ',');
			}
		}
	}
}
