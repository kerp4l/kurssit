#include <stdio.h>

#define MAX 999
#define N 6




int main() {

int aloitus = 0;
int i, j, k, min, seuraava;
int etaisyys[N], vieraillut[N], edelliset[N];


int A[N][N] = {
	{MAX, 5,15,MAX, MAX, MAX},
	{5, MAX, 6, 4, 10, MAX},
	{15, 6, MAX, 7, MAX, MAX},
	{MAX, 4, MAX, MAX, 5, 12},
	{MAX, 10, 7, 5, MAX, 3},
	{MAX, MAX, MAX, 12, 3, MAX}
};


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
		printf("Solmu %d:\n", i + 1);
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




