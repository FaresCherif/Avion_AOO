#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include "Passager.h"


using namespace std;

void menuAdmin() {
	cout << "             =====  Choix  ====="<<"\n";
	cout << "1  -- Modifier la Date d un vol" << "\n";
	cout << "2  -- Modifier l heure d un vol" << "\n";
	cout << "3  -- Ajouter vol" << "\n";
	cout << "4  -- Afficher liste des vols" << "\n";
	cout << "5  -- Quitter et savegarder" << "\n";
	cout << "6  -- Quitter sans savegarder" << "\n";
}

void menuUtilisateur() {
	cout << "             =====  Choix  =====" << "\n";
	cout << "1  -- Reserver un vol" << "\n";
	cout << "2  -- Gerer ses reservations" << "\n";
	cout << "3  -- Verfier vol" << "\n";
	cout << "4  -- Afficher liste des vols" << "\n";
	cout << "5  -- Quitter et savegarder" << "\n";
	cout << "6  -- Quitter sans savegarder" << "\n";
}

int main() {
	int choix = 0;

	while (choix != 6) {
		string admin = "n";
		cout << "etes vous admin ? (y/n)";
		cin >> admin;

		if (admin == "y") {
			choix = 0;
			ifstream fichier;
			fichier.open("Administrateur.txt", ios::in);

			string ligne;

			while (fichier)    //Tant qu'on n'est pas a la fin
			{
				getline(fichier, ligne); //On lit une ligne
			}

			string mdp;
			cout << "Tapez le mot de passe Administrateur : ";
			cin >> mdp;

			if (mdp == ligne) {
				cout << "vous etes connecte" << "\n";
				int choixMenu = 0;


				while (choixMenu != 5 && choixMenu != 6) {
					menuAdmin();
					cin >> choixMenu;

					if (choixMenu == 1) {
						Passager passager = Passager();

					}

					else {
						if (choixMenu == 3) {
							int nbplace;
							cout << "Nombre de place dans ce vol : ";

							cin >> nbplace;
						}

						else {
							if (choixMenu == 6) {
								choixMenu = 6;
								choix = 6;
							}
							else {
								cout << "Le symbole entre n est pas accepte" << "\n";

							}
						}


					}
				}

			}


			else {
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
			case 2: cout << "Le symbole rentre n est pas accepte" << "\n"; break;
			case 6: cout << "Au revoir" << "\n";
			}



		}
	}
}