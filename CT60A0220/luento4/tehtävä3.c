#include <stdio.h>

/*Topi Jussinniemi, 2.2.2018, harjoitus 4, tehtävä 3*/

void tulosta(int matriisi[2][2], char nimi[]);


int main(void) {

int m1[2][2];
int m2[2][2];
int m3[2][2];
int i;
int j;
char nimi1[] = "Matriisi 1";
char nimi2[] = "Matriisi 2";
char nimi3[] = "Summamatriisi";


printf("Anna arvot yhteenlaskettaville matriiseille:\n");

printf("Matriisin 1 alkiot:\n");
printf("Rivi 1 alkio 1: ");
scanf("%d", &m1[0][0]);

printf("Rivi 1 alkio 2: ");
scanf("%d", &m1[0][1]);

printf("Rivi 2 alkio 1: ");
scanf("%d", &m1[1][0]);

printf("Rivi 2 alkio 2: ");
scanf("%d", &m1[1][1]);

tulosta(m1, nimi1);

printf("\n");
printf("Matriisin 2 alkiot:\n");
printf("Rivi 1 alkio 1: ");
scanf("%d", &m2[0][0]);

printf("Rivi 1 alkio 2: ");
scanf("%d", &m2[0][1]);
printf("Rivi 2 alkio 1: ");
scanf("%d", &m2[1][0]);

printf("Rivi 2 alkio 2: ");
scanf("%d", &m2[1][1]);


for (i = 0; i < 2; i++) {
	for (j = 0; j < 2; j++) {
		m3[i][j] = m1[i][j] + m2[i][j];
	}
}

tulosta(m2, nimi2);
tulosta(m3, nimi3);

return 0;
}

void tulosta(int matriisi[2][2], char nimi[]) {
int i;
int j;

printf("\n");
printf("%s:\n", nimi);

for (i = 0; i < 2; i++) {
	for (j = 0; j < 2; j++) {
		printf("   %d", matriisi[i][j]);
		if (j == 1) {
			printf("\n");
		}
	}
}

}


/*eof*/
