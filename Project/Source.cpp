#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include "Passager.h"
#include "Destination.h"
#include "Date.h"

using namespace std;

void menuAdmin() {
	cout << "             =====  Choix  ====="<<"\n";
	cout << "1  -- Gerer les destinations" << "\n";
	cout << "2  -- Gerer vol" << "\n";
	cout << "3  -- Gerer passager" << "\n";
	cout << "4  -- Afficher liste des vols" << "\n";
	cout << "5  -- Quitter et savegarder" << "\n";
	cout << "6  -- Quitter sans savegarder" << "\n";
}

void menuDestination() {
	cout << "1  -- Afficher les destinations" << "\n";
	cout << "2  -- Chercher ville de depart" << "\n";
	cout << "3  -- Chercher ville d arrivee" << "\n";
	cout << "4  -- Ajouter destination" << "\n";
	cout << "5  -- Quitter" << "\n";
}

void menuDate() {
	cout << "1  -- Afficher les Date" << "\n";
	cout << "2  -- Ajouter Date" << "\n";
	cout << "3  -- Quitter" << "\n";
}

void menuPassager() {
	cout << "1  -- Afficher les passagers" << "\n";
	cout << "2  -- Ajouter passager" << "\n";
	cout << "3  -- Quitter" << "\n";
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
	int choixDestination = 0;
	int choixDate = 0;
	int choixPassager = 0;

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
						while (choixDestination != 5) {

							Destination destination;
							menuDestination();
							cin >> choixDestination;

							if (choixDestination == 1) {
								destination.afficherDestination();
							}
							else {

								if (choixDestination == 2) {
									destination.chercherVilleDepart();

								}
								else {

									if (choixDestination == 3) {
										destination.chercherVilleArrive();
									}
									else {
										if (choixDestination == 4) {
											destination.crerDestination();
										}
										else {
											if (choixDestination == 5) {

											}
											else {
												cout << "Charactere non accepté";
											}
										}
									}
								}
							}
						}
					}

					else {

						if (choixMenu == 2) {
							while (choixDate != 3) {

								Date date;
								menuDate();
								cin >> choixDate;

								if (choixDate == 1) {
									date.afficherDate();
								}
								else {

									if (choixDate == 2) {
										date.creerDate();
									}

									else {
										if (choixDate == 3) {

										}
										else {
											cout << "Charactere non accepté";
										}
									}
										
									
								}
							}
						}
						else {


							if (choixMenu == 3) {
								while (choixPassager != 3) {

									Passager passager;
									menuPassager();
									cin >> choixPassager;

									if (choixPassager == 1) {
										passager.afficherPassager();
									}
									else {

										if (choixPassager == 2) {
											passager.creerPassager();
										}

										else {
											if (choixPassager == 3) {

											}
											else {
												cout << "Charactere non accepté";
											}
										}


									}
								}
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

	}
}
