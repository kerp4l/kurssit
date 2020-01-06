/*Topi Jussinniemi, 25.2.2018, harjoitus 7, tehtävä 1*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void arvoNumerot(int *lista, int koko) {
int i;
int luku;
srand(40);
luku = rand()%38;
lista[0] = luku;
int temp = 2;

for (i = 1; i < koko; i++) {
	temp = 1;
	while(temp != 0) {
		luku = rand()%38;
		temp = tarkistaNumero(lista, luku, i);
		if(temp == 0) {
			lista[i] = luku;
		}
	}
}

}



int tarkistaNumero(int *lista, int luku, int koko) {
int i;
int palautus = 0;
int temp = 0;

for (i = 0; i < koko; i++) {
	if ((lista[i] == luku) || (luku == temp)) {
		palautus = 1;
	}
}
return palautus;
}



void tulostaNumerot(int *lista, int koko) {
int i;

for(i = 0; i < koko; i++) {
	printf(" %d", lista[i]);
}
printf("\n");
}




