
/*********************************
Auteur: Solange Desjardins
Date: 17 janvier 2022
Nom du programme: TP8
Description: Gerer les données d'inventaire, faire des commandes et faire la facturation.
*********************************/


#include <iostream>   
#include <conio.h>
#include <iomanip> 
#include <string> 
#include <Windows.h> 
#include "C:\\cvm.h" 
#include <cstdlib>
#include <C:\\Tp8\tp8.h>
using namespace std;



void main(void)
{
	const int MAXPRODUIT = 150;
	const float TPS = 0.05f;
	const float TVQ = 0.09975f;
	int Reponse;
	int NombreProduits;
	int NoProduit[MAXPRODUIT];
	float PrixProduit[MAXPRODUIT];
	int QteProduit[MAXPRODUIT];
	int NoProdLu = 0;
	int QteDesiree = 0;
	int QteVendue = 0;

	NombreProduits = LireInventaire(NoProduit, QteProduit, PrixProduit);



	Reponse = MessageBoxA(NULL, "Désirez-vous entrer une commande? ", "Système des commandes", MB_YESNO | MB_ICONQUESTION);

	while (Reponse == IDYES)
	{
		cout << "Entrez un num\x82ro de produit : ";
		cin >> NoProdLu;
		bool EstValide = false;

		for (int i = 0; i <= MAXPRODUIT; i++)
		{

			if (NoProdLu == NoProduit[i])
			{
				EstValide = true;
				cout << "Entrez une quantit\x82 valide: ";
				cin >> QteDesiree;




				while (QteDesiree <= 0)
				{
					MessageBoxA(NULL, " La quantité doit être strictement supérieur à 0 ", "Erreur de saisi", MB_OK | MB_ICONSTOP);


					//revenir  question quantite

					gotoxy(28, 1);
					clreol();

					cin >> QteDesiree;

				}




				if (QteProduit[i] <= 0)
				{
					MessageBoxA(NULL, "Produit en rupture de stock. ", "Problème de commande", MB_OK | MB_ICONINFORMATION);

					EcrireInventaire(NoProduit, QteProduit, PrixProduit, NombreProduits);
					QteProduit[i] = QteProduit[i] - QteDesiree;

					Reponse = MessageBoxA(NULL, "Désirez-vous entrer une commande? ", "Système des commandes", MB_YESNO | MB_ICONQUESTION);
					clrscr();
				}




				if ((QteDesiree < QteProduit[i]) && QteProduit[i] > 0)
				{
					//Facture
					clrscr();

					cout << "\t\t\tAlius ulcus carceris Inc.\n";
					cout << "\n\n\n\n\n \t\t Commande pour le produit: " << NoProdLu;
					cout << "\n\n" << QteDesiree << " \x85 " << PrixProduit[i] << " l\'unit\x82";
					float PrixCalcul = QteDesiree * PrixProduit[i];
					cout << " \t\t\t... $  " << PrixCalcul << setprecision(2) << fixed;
					cout << "\n Taxe TPS \t\t" << " \t\t... $  " << TPS * (PrixProduit[i] * QteDesiree) << setprecision(2) << fixed;
					cout << "\n Taxe TVQ \t\t" << " \t\t... $  " << TVQ * (PrixProduit[i] * QteDesiree) << setprecision(2) << fixed;
					cout << "\n Grand Total" << " \t\t\t\t... $  " << (PrixCalcul + (TPS * PrixCalcul) + (TVQ * PrixCalcul)) << setprecision(2) << fixed;

					EcrireInventaire(NoProduit, QteProduit, PrixProduit, NombreProduits);
					QteProduit[i] = QteProduit[i] - QteDesiree;

					cout << " \n\n\n\n\n\nappuyez sur une touche pour continuer";
					_getch();

					Reponse = MessageBoxA(NULL, "Désirez-vous entrer une commande? ", "Système des commandes", MB_YESNO | MB_ICONQUESTION);
					clrscr();
				}




				else if ((QteDesiree > QteProduit[i]) && QteProduit[i] > 0)
				{
					//Facture

					MessageBoxA(NULL, "Nous ne pouvons pas répondre entièrement à votre commande. ", "Problème de commande", MB_OK | MB_ICONINFORMATION);

					clrscr();

					cout << "\t\t\tAlius ulcus carceris Inc.\n";
					cout << "\n\n\n\n\n \t\t Commande pour le produit: " << NoProdLu;
					cout << "\n\n" << QteProduit[i] << " \x85 " << PrixProduit[i] << " l\'unit\x82" << setprecision(2) << fixed;
					float PrixCalcul = QteProduit[i] * PrixProduit[i];
					cout << " \t\t\t... $  " << PrixCalcul << setprecision(2) << fixed;
					cout << "\n Taxe TPS \t\t" << " \t\t... $  " << TPS * (PrixProduit[i] * QteProduit[i]) << setprecision(2) << fixed;
					cout << "\n Taxe TVQ \t\t" << " \t\t... $  " << TVQ * (PrixProduit[i] * QteProduit[i]) << setprecision(2) << fixed;
					cout << "\n Grand Total" << " \t\t\t\t... $  " << (PrixCalcul + (TPS * PrixCalcul) + (TVQ * PrixCalcul)) << setprecision(2) << fixed;

					EcrireInventaire(NoProduit, QteProduit, PrixProduit, NombreProduits);
					QteProduit[i] = QteProduit[i] - QteDesiree;

					cout << " \n\n\n\n\n\nappuyez sur une touche pour continuer";
					_getch();

					Reponse = MessageBoxA(NULL, "Désirez-vous entrer une commande? ", "Système des commandes", MB_YESNO | MB_ICONQUESTION);
					clrscr();


				}


			}



		}
		if (!EstValide)
		{
			MessageBoxA(NULL, " Ce produit n'existe pas. ", "Erreur de saisi", MB_OK | MB_ICONSTOP);
			clrscr();
		}




	}

}