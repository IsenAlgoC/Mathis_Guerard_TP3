#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>
#define carre(x) (x) * (x)

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
	int indice = 1;
	float note;
	char condition_arret = 'N';

	while (indice <= 30) {
		printf("\nEntrez la note no %d : ", indice);
		scanf_s("%f", &note);
		indice++;
		if (note < 0 || note > 20) {
			printf("Eleve absent ? Ou voulez-vous arrêter la saisie des notes ? a/o/n ");
			condition_arret = toupper(_getch());
			switch (condition_arret) {
			case 'A' :

			case ''
			}
		}
	}
	


	printf("\n\n");
	system("pause");
}