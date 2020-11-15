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
}
