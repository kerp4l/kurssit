/*
BM40A0301 Tietorakenteet ja algoritmit
Harjoitus 5, tehtävä 2
Topi Jussinniemi 0401301
*/

#include <stdio.h>



int main(void) {

int i, j,  k;

int x = 9999; /*Jokin suuri luku, jolla voidaan merkitä, että kahden solmun välillä ei ole kaarta.*/
int n = 6; /*Solmujen lukumäärä.*/

/*Alustetaan tehtävänannossa esitetyn graafin solmujen väliset painotukset matriiisiin d.*/
int d[6][6] = {
	{0, 4, x, x, 5, x},
	{4, 0, 6, x, x, 1},
	{x, 6, 0, 1, x, 2},
	{x, x, 1, 0, 2, 4},
	{5, x, x, 2, 0, x},
	{x, 1, 2, 4, x, 0}
};

/*Tulostetaan matriisi d.*/
printf("Painotettu graafi on muotoa:\n");

for (i = 0; i < n; i++) {
	printf("\n");
	for (j = 0; j < n; j++) {
		if(d[i][j] == x) {
			printf("- ");
		} else {
			printf("%d ", d[i][j]);
		}		
	}
}


/*Floydin algoritmin suoritus.*/
for (i = 0; i < n; i++) {
	for (j = 0; j < n; j++) {
		for (k = 0; k < n; k++){
				if (d[j][k] > (d[j][i] + d[i][k])) {
					d[j][k] = d[j][i] + d[i][k];
				} 			
		}
	}
}


/*Tulostetaan ratkaisu.*/
printf("Solmujen väliset lyhimmät reitit ovat pituuksiltaan seuraavanlaiset:");

for (i = 0; i < n; i++) {
	printf("\n");
	for (j = 0; j < n; j++) {
		printf("%d ", d[i][j]);
	}
}

printf("\n");



return 0;
}

/*eof*/
