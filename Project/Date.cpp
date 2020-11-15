#include "Date.h"



Date::Date()
{
	cout << "Jour : ";
	cin >> jour;
	cout << "Mois : ";
	cin >> mois;
	cout << "Annee : ";
	cin >> annee;
	cout << "Heure : ";
	cin >> heure;
	cout << "Minute : ";
	cin >> minute;

	this->jour = jour;
	this->mois = mois;
	this->annee = annee;
	this->heure = heure;
	this->minute = minute;
}

Date::Date(int jour,int mois, int annee,int heure, int minute)
{
	this->jour = jour;
	this->mois = mois;
	this->annee = annee;
	this->heure = heure;
	this->minute = minute;
}

Date::~Date()
{
	cout << "Entrez le jour en chiffre : ";
	cin >> jour;
	this->jour = jour;

	cout << "Entrez le mois en chiffre : ";
	cin >> mois;
	this->mois = mois;

	cout << "Entrez l annee : ";
	cin >> annee;
	this->annee = annee;

	cout << "Entrez l heure : ";
	cin >> heure;
	this->heure = heure;

	cout << "Entrez les minutes : ";
	cin >> minute;
	this->minute = minute;
}
