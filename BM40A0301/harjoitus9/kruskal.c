/*
BM40A0301 Tietorakenteet ja algoritmit
Harjoitus 9, tehtävä 1
Topi Jussinniemi 0401301
Lähde: https://www.thecrazyprogrammer.com/2014/03/kruskals-algorithm-for-finding-minimum-cost-spanning-tree.html
*/


#include <stdio.h>

#define MAX 15

struct Node {
	int kaari;
	int solmu;
	int paino;
};

typedef struct Node kaari;

struct Node2 {
	kaari data[MAX];
	int n;
};

typedef struct Node2 kaariLista;

kaariLista kaari_lista;
kaariLista pvp_lista;

int A[MAX][MAX] = {
	{0, 4, 5, 0, 0},
	{4, 0, 6, 9, 0},
	{5, 6, 0, 6, 12},
	{0, 9, 6, 0, 5},
	{0, 0, 12, 5, 0}
};


int etsi(int k[], int);
void yhdista(int k[], int, int, int);

int main() {

int n = 5;
int i, j;
kaari temp_kaari;
int kuuluu[MAX];
int joukko1, joukko2;
int pvp_paino = 0;


/*Luetaan matriisita graafissa olevat kaaret eri solmujen välillä.*/
/*Tulostetaan samalla graafissa olevien kaarien painotukset.*/

kaari_lista.n = 0;

printf("Graafissa olevien kaarien painotukset ovat: ");

for (i = 1; i < n; i++) {
	for (j = 0; j < i; j++) {
		if (A[i][j] != 0) {
			kaari_lista.data[kaari_lista.n].solmu = i;
			kaari_lista.data[kaari_lista.n].kaari = j;
			kaari_lista.data[kaari_lista.n].paino = A[i][j];
			kaari_lista.n = kaari_lista.n + 1;
			printf("%d ", A[i][j]);
		}
	}
}
printf("\n");


/*Jätjestetään kaaret pienimmästä suurimpaan painotusten mukaan.*/

for (i = 1; i < kaari_lista.n; i++) {
	for (j = 0; j < (kaari_lista.n - 1); j++) {
		if (kaari_lista.data[j].paino > kaari_lista.data[j + 1].paino) {
			temp_kaari = kaari_lista.data[j];
			kaari_lista.data[j] = kaari_lista.data[j + 1];
			kaari_lista.data[j + 1] = temp_kaari;
		}
	}
}

/*Tulostetaan järjestetyt kaarten painotukset.*/

printf("Graafissa olevien kaarten painotukset pienimmästä suurimpaan; ");

for (i = 0; i < kaari_lista.n; i++) {
	printf("%d ", kaari_lista.data[i].paino);
}

printf("\n");


for (i = 0; i < n; i++) {
	kuuluu[i] = i;
}


/*Pienimmän virittävän puun rakentaminen.*/

pvp_lista.n = 0;

for (i = 0; i < (kaari_lista.n - 1); i++) {
	joukko1 = etsi(kuuluu, kaari_lista.data[i].kaari);
	joukko2 = etsi(kuuluu, kaari_lista.data[i].solmu);
	if (joukko1 != joukko2) {
		pvp_lista.data[pvp_lista.n] = kaari_lista.data[i];
		pvp_lista.n = pvp_lista.n + 1;
		yhdista(kuuluu, joukko1, joukko2, n);
	}
}

/*Tulostetaan kaaret joista pienin viittävä puu koostuu ja puun kaarien painojen summa.*/

printf("Pienin virittävä puu koostuu seuraavista kaarista: \n");


for (i = 0; i < pvp_lista.n; i++) {
	temp_kaari = pvp_lista.data[i];
	pvp_paino = pvp_paino + temp_kaari.paino;
	printf("Solmusta %d ", temp_kaari.solmu + 1);
	printf("solmuun %d ", temp_kaari.kaari + 1);
	printf("kaaren painotus on %d\n", temp_kaari.paino);
	
}

printf("Pienimmän virittävän puun kaarien painotusten summa on: %d\n", pvp_paino);


return 0;
}



/*Aliohjelma joka palauttaa sen kaarijoukon johon syötteenä annettu kaari kuuluu.*/

int etsi(int kuuluu[], int solmu) {
	return (kuuluu[solmu]);
}



/*Aliohjelma joka yhdistää kaksi kaarijoukkoa.*/

void yhdista(int kuuluu[], int a, int b, int n) {

int i;

for (i = 0; i < n; i++) {
	if (kuuluu[i] == b) {
		kuuluu[i] = a;
	}
	
}
}


/*eof*/
