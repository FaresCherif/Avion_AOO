#include "Reservation.h"



Reservation::Reservation()
{
	cout << "Numero de Passeport : ";
	cin >> numPasseport;
	cout << "Numero de Reservation : ";
	cin >> numReservation;
	cout << "Numero de Vol ";
	cin >> numVol;
	cout << "Est ce confirme : (y/n)";
	string motConfirmation;
	cin >> motConfirmation;

	if (motConfirmation == "y") {
		this->confirmation = true;
	}
	else {
		this->confirmation = false;
	}

	this->numPasseport = numPasseport;
	this->numReservation = numReservation;
	this->numVol = numVol;
}

Reservation::Reservation(string numReservation,string numPasseport,string numVol, bool confirmation)
{
	this->numReservation = numReservation;
	this->numPasseport = numPasseport;
	this->numVol = numVol;
	this->confirmation = confirmation;
}

Reservation::~Reservation()
{
}
