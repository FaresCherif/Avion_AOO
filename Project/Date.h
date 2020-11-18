#pragma once
#include <string>
#include <vector>
#include <iostream>


using namespace std;

class Date
{
	string date;
	string heure;
public:
	Date();
	Date(string, string );
	void creerDate();
	void afficherDate();
	void chercherDate();

	~Date();
};

