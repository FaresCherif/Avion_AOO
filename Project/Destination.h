#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Destination
{
	string villeDepart;
	string villeArrive;

public:
	Destination();
	Destination(string,string);
	~Destination();
};

