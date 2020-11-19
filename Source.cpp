#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include "Passager.h"
#include "Destination.h"
#include "Date.h"
#include "Vol.h"

using namespace std;

void menuAdmin() {
	cout << "             =====  Choix  ====="<<"\n";
	cout << "1  -- Gerer les destinations" << "\n";
	cout << "2  -- Gerer date" << "\n";
	cout << "3  -- Gerer passager" << "\n";
	cout << "4  -- Gerer vols" << "\n";
	cout << "5  -- Quitter" << "\n";
}

void menuDestination() {
	cout << "             =====  Destination  =====" << "\n";
	cout << "1  -- Afficher les destinations" << "\n";
	cout << "2  -- Ajouter destination" << "\n";
	cout << "3  -- Quitter" << "\n";
}

void menuDate() {
	cout << "             =====  Date  =====" << "\n";
	cout << "1  -- Afficher les Date" << "\n";
	cout << "2  -- Ajouter Date" << "\n";
	cout << "3  -- Quitter" << "\n";
}

void menuPassager() {
	cout << "             =====  Passager  =====" << "\n";
	cout << "1  -- Afficher les passagers" << "\n";
	cout << "2  -- Ajouter passager" << "\n";
	cout << "3  -- Quitter" << "\n";
}

void menuVol() {
	cout << "             =====  Vol  =====" << "\n";
	cout << "1  -- Afficher les vols" << "\n";
	cout << "2  -- Ajouter vol" << "\n";
	cout << "3  -- Chercher vol par numero" << "\n";
	cout << "4  -- Chercher vol partant d une ville" << "\n";
	cout << "5  -- Chercher vol arrivant dans une ville" << "\n";
	cout << "6  -- Quitter" << "\n";
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


				while (choixMenu != 5) {
					int choixDestination = 0;
					int choixDate = 0;
					int choixPassager = 0;
					int choixVol = 0;

					menuAdmin();
					cin >> choixMenu;

					if (choixMenu == 1) {
						while (choixDestination != 3) {

							Destination destination;
							menuDestination();
							cin >> choixDestination;

							if (choixDestination == 1) {
								destination.afficherDestination();
							}
							else {

								if (choixDestination == 2) {
									destination.crerDestination();
								}
								
								else {
									if (choixDestination == 3) {
										
									}
									else {
										cout << "Charactere non accepté";
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
								if (choixMenu == 4) {
									while (choixPassager!=6) {
										menuVol();
										Vol vol;
										cin >> choixPassager;

										if (choixPassager == 1) {
											vol.afficherVol();
										}
										else {
											if (choixPassager == 2) {
												vol.creerVol();
											}
											else {
												if (choixPassager == 3) {
													string numVol;
													cout << "Entrez le numero recherche : ";
													cin >> numVol;
													vol.chercherParNum(numVol);
												}
												else {
													if (choixPassager == 4) {
														cout << "Entrez la ville de depart : ";
														string villeDepart;
														cin >> villeDepart;
														vol.chercherParVilleDepart(villeDepart);
													}
													else {
														if (choixPassager == 5) {

															cout << "Entrez la ville d arrivee : ";
															string villeArrive;
															cin >> villeArrive;
															vol.chercherParVilleArrivee(villeArrive);
														}
														else {
															if (choixPassager == 6) {

															}
														}
													}
												}
											}
										}
									}

								}
								else {
									if (choixMenu == 5) {
										choixMenu = 5;
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
