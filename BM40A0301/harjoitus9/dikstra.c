/*
BM40A0301 Tietorakenteet ja algoritmit
Harjoitus 9, tehtävä 2
Topi Jussinniemi 0401301
Lähde: https://www.thecrazyprogrammer.com/2014/03/dijkstra-algorithm-for-finding-shortest-path-of-a-graph.html
*/
/*Vakiot: 
MAX cain jokin suuri luku kuvaamaan ääretlntä etäisyytt.
N on graafissa olevien solmujen lukumäärä.*/
#include <stdio.h>

#define MAX 999
#define N 10

int main() {

int aloitus = 0;
int i, j, k, min, seuraava;
int etaisyys[N], vieraillut[N], edelliset[N];


int A[N][N] = {
	{MAX, 25, 6, MAX, MAX, MAX, MAX, MAX, MAX, MAX},
	{25, MAX, MAX, 10, 3, MAX, MAX, MAX, MAX, MAX},
	{6, MAX, MAX, 7, MAX, 15, MAX, MAX, MAX, MAX},
	{MAX, 10, 7, MAX, 12, 15, 4, 15, 20, MAX},
	{MAX, 3, MAX, 12, MAX, MAX, MAX, 2, MAX, MAX},
	{MAX, MAX, 25, 15, MAX, MAX, MAX, MAX, 2, MAX},
	{MAX, MAX, MAX, 4, MAX, MAX, MAX, 8, 13, 15},
	{MAX, MAX, MAX, 15, 2, MAX, 8, MAX, MAX, 5},
	{MAX, MAX, MAX, 20, MAX, 2, 13, MAX, MAX, 1},
	{MAX, MAX, MAX, MAX, MAX, MAX, 15, 5, 1, MAX}
};


/*Taulukoiden alustaminen.*/

for (i = 0; i < N; i++) {
	etaisyys[i] = A[aloitus][i];
	edelliset[i] = aloitus;
	vieraillut[i] = 0;
}


etaisyys[aloitus] = 0;
vieraillut[aloitus] = 1;
k = 1;


while (k < (N - 1)) {
	min = MAX;

/*Lyhimmän etäisyyden päässä olevan solmun etsiminen.*/

	for (i = 0; i < N; i++) {
		if ((etaisyys[i] < min) && (vieraillut[i] == 0)) {
			min = etaisyys[i];
			seuraava = i;
		}
	}

/*Tutkitaan johtaako uudessa solmussa vieraileminen uusiin lyhimpiin reitteihin muihin solmuihin.*/
		vieraillut[seuraava] = 1;
		for (i = 0; i < N; i++) {
			if (vieraillut[i] == 0) {
				if (min + A[seuraava][i] < etaisyys[i]) {
					etaisyys[i] = min + A[seuraava][i];
					edelliset[i] = seuraava;
				}
			}
		}
	
k = k + 1;
}



/*Tulosten tulostaminen*/

printf("Graafissa olevien solmujen etäisyydet ja reitit solmusta%d ovat:\n", aloitus + 1);

for (i = 0; i < N; i++) {
	if (i != aloitus) {
		printf("\n");
		printf("Solmu %d\n", i + 1);
		printf("Etäisyys: %d\n", etaisyys[i]);
		printf("Reitti: %d", i + 1);
	
		k = 0;
		j = i;
		do {
			j = edelliset[j];
			k = k + 1;
			printf(" -> %d", j + 1);
		}while (j != aloitus);

	printf("\n");
	}
}

return 0;
}

/*eof*/
