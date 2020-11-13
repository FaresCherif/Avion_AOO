#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>


using namespace std;

int main() {
	int choix = 0;

	while (choix != 5) {
		string admin = "n";
		cout << "etes vous admin ? (y/n)";
		cin >> admin;
		
		if (admin == "y") {
			choix = 0;
		}
		else{
			if (admin == "n") {
				choix = 1;
			}
			else {
				choix = 2;
			}
		}


		switch (choix) {
		case 0:; break;
		case 1:; break;
		case 2: cout<<"Le symbole rentre n est pas accepte"<<"\n"; break;

		}



	}

}