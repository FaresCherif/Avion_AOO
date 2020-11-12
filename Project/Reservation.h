#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Reservation
{
	string numReservation;
	string numPasseport;
	string numVvol;
	bool confirmation;

public:
	Reservation();
	~Reservation();
};

