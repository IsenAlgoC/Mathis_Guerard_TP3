#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>
#include <stdbool.h>
#include "fct.h"
#define carre(x) (x) * (x)
#define NBMAXNOTES 30

void main() {
	
	//Exercice 1
	int Nb = 5;
	printf("%d", carre(Nb));
	printf("\n%d", carre(Nb + 1));

	//Exercice 2
	unsigned long entier = 2868838400;
	int bits = (unsigned int)(log(entier) / log(2) + 1);
	int octets = (unsigned int)(bits / 8) + 1;
	int compteur = 1;

	printf("\nNombre de bits : %d\nNombre d'octets : %d", bits, octets);
	while (compteur <= bits) {
		if (entier & 1) {
			printf("\nBit numero %d : ON", compteur);
			compteur++;
			entier >>= 1 ;
		}
		else {
			printf("\nBit numero %d : OFF", compteur);
			compteur++;
			entier >>= 1;
		}
	}
	printf("\n\nBye");

	//Exercice 3
	int indice = 0;
	float noteTmp;
	float somme = 0;
	float moyenne = 0;
	char condition_arret = 'N';
	int nbrNoteValide = 0;
	int absence = 0;
	float max = 0;
	float min = 20;
	float ecart = 0;
	float ecartType = 0;
	float copienote[NBMAXNOTES] = { 0 };
	int index[NBMAXNOTES] = { 0 };
	bool arret = false;
	float note[NBMAXNOTES];

	for (int i = 0; i < NBMAXNOTES; i++) {		//initialiser le tableau de valeur à -2
		note[i] = -2;
	}

	while ((indice <= 30) && (arret == false)) {
		printf("\nEntrez la note no %d : ", indice+1);
		scanf_s("%f", &noteTmp);

		if (noteTmp < 0 || noteTmp > 20) {			//si la note sort de [O,20] on demande l'arret du programme
			printf("Eleve absent ? Ou voulez-vous arrêter la saisie des notes ? a/o/n ");
			condition_arret = toupper(_getch());		//pour demander à l'utilisateur de rentrer une lettre
			switch (condition_arret) {
			case ('A') :		//si a, on rajoute une absence
				note[indice] = -1;
				indice++;
				absence++;
				break;
			case ('O') :		//si o, on quitte la boucle while
				arret = true;
				break;
			case ('N') :		//si n, on recommence la saisie de la même note
				break;
			default :			//sinon on demande à retaper la lettre
				printf("\n\nVeuillez retaper a/o/n ");
				break;
			}
		}
		else {				//cas où la note tapée est correcte
			note[indice] = noteTmp;
			somme = somme + noteTmp;
			nbrNoteValide++;
			indice++;
			if (noteTmp > max) {
				max = noteTmp;
			}
			if (noteTmp < min) {
				min = noteTmp;
			}
		}
	}
	moyenne = somme / (float)nbrNoteValide;
	printf("\nMoyenne : %.2f", moyenne);
	printf("\nAbsences : %d", absence);
	printf("\nMax : %.2f \nMin : %.2f", max, min);
	printf("\n\n");
	for (int i = 0; i < NBMAXNOTES; i++) {		//afficher le tableau de notes
		printf("%.2f   ", note[i]);
	}
	//calcul de l'écart type
	for (int i = 0; i < NBMAXNOTES; i++) {
		if (note[i] >= 0) {
			ecart = ecart + pow(((double)(note[i]) - (double)(moyenne)), 2);
		}
	}
	ecartType = sqrtl(ecart / (float)(nbrNoteValide - 1));
	printf("\nEcart type : %f", ecartType);

	//on trie le tableau de notes dans l'ordre décroissant
	//tri à bulles
	for (int i = 0; i < NBMAXNOTES; i++) {		//création de tableau annexe (copie)
		if (note[i] >= 0) {
			copienote[i] = note[i];
			index[i] = i;
		}
	}
	for (int i = 1; i <= NBMAXNOTES; i++) {		//permutation
		while (copienote[i - 1] > copienote[i]) {
			copienote[i-1], copienote[i] = permutation(copienote[i - 1], copienote[i]);
			index[i-1], index[i] = permutation((float)(index[i - 1]), (float)index[i]);
		}
	}
	for (int i = 0; i < NBMAXNOTES; i++) {		//afficher le tableau de notes
		printf("\n\n%.2f  : position : %d", copienote[i], index[i]);
	}

	printf("\n\n");
	system("pause");
}