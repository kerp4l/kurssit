/*
BM40A0301 Tietorakenteet ja algoritmit
Harjoitus 6, tehtävä 4
Topi Jussinniemi 0401301
*/

#include <stdio.h>
#include <math.h>


int main(void) {

int i, j, n, raja;

printf("Ohjelma laskee tiettyyn pisteeseen asti löytyvät alkuluvut käyttäen Eratostheneen seulaa.\n");

/*Pyydetään käyttäältä tieto siitä mihin asti etsitään alkuluvut.*/
printf("Anna yläraja johon asti etsitään alkuluvut: ");
scanf("%d", &n);

raja = sqrt(n);

/*Luodaan annetun syötteen kokoa vastaava lista.*/

int lista[n];

for (i = 1; i <= n; i++) {
	lista[i-1] = i;
}

printf("Välillä 0 - %d on seuraavat alkuluvut:\n", n);

/*Sijoitetaan 0 lukujen tilalle, jotka eivät ole alkulukuja.*/

for (i = 2; i <= raja; i++)  {
	for (j = 0; j < n; j++) {
		if (((lista[j]/i) > 1) && ((lista[j]%i) == 0)) {
			lista[j] = 0;
		}
	}
}

/*Tulostetaan löydetyt alkuluvut.*/

for (i = 0; i < n; i++) {
	if (lista[i] > 0) {
		printf("%d ", lista[i]);
	}
}

printf("\n");

return 0;
}


/*eof*/
