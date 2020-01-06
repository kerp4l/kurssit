/*
BM40A0301 Tietorakenteet ja algoritmit
Harjoitus 2, tehtävä 2
Topi Jussinniemi 0401301
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

int i, j, n;
int lopetus = 0;

printf("Ohjelma arpoo 2-100 satunnaista lukua väliltä 0-99 ja järjestää ne pienimmästä suurimpaan.\n");

while (lopetus != 1) {
	printf("Montako satunnaislukua lajitellaan: ");
	scanf("%d", &n);
	
	if (n < 2 || n > 100) {
		printf("Virheellinen syöte! Anna lukumäärä väliltä 2-100.\n");
	}
	else {
		int lista[n];
		
		printf("Arvotut satunnaisluvut: ");
		for (i = 0; i < n; i++) {
			int luku = rand()%100;
			printf("%d ", luku);
			lista[i] = luku;
		}
		printf("\n");
		
		lopetus = 1;
		
		/*Limittäislajittely*/
		
		for (i = 1; i <= (n - 1); i++) {
			for (j = (n - 1); j >= i; j--) {				
				if (lista[j - 1] > lista[j]) {
					int temp = lista[j];
				lista[j] = lista[j - 1];
				lista[j - 1] = temp;
				}
			}
		}
	/*Järjestetyn listan tulostaminen*/
	
	printf("Satunnaisluvut pienimmästä suurimpaan: ");
	for (i = 0; i < n; i++) {
		printf("%d ", lista[i]);
	}
	printf("\n");

	}
}

return 0;
}

/*eof*/
