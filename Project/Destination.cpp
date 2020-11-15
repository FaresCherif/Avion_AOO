#include "Destination.h"
#include <iostream>

using namespace std;

Destination::Destination()
{
	cout << "Ville de depart : ";
	cin >> villeDepart;

	cout << "Ville d arrivee : ";
	cin >> villeArrive;

	this->villeDepart = villeDepart;
	this->villeArrive = villeArrive;
}

Destination::Destination(string villeDepart,string villeArrive) {
	this->villeArrive = villeArrive;
	this->villeDepart = villeDepart;
}



Destination::~Destination()
{
}
