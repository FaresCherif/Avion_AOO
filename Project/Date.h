#pragma once
#include <string>
#include <vector>
#include <iostream>


using namespace std;

class Date
{
	int jour;
	int mois;
	int annee;

	int heure;
	int minute;
public:
	Date();
	Date(int, int,int, int , int );
	~Date();
};

