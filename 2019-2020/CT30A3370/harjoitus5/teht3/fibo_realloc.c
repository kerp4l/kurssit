/*
CT30A33170 Käyttöjärjestelmät ja systeemiohjelmointi
Harjoitus 5, tehtävä 3
Topi Jussinniemi
fibo_realloc.c
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

int *fibo, i;
fibo = (int *) malloc(sizeof(int) * 10);

if (fibo == NULL) {
	perror("Muistin varaaminen epäonnistui!\n");
	exit(1);
}

fibo[0] = 1;
fibo[1] = 1;
fibo[2] = 2;
fibo[3] = 3;
fibo[4] = 5;
fibo[5] = 8;
fibo[6] = 13;
fibo[7] = 21;
fibo[8] = 34;
fibo[9] = 55;

printf("Listassa on 10 ensimmäistä fibonaccin lukua, jotka ovat:\n");

for (i = 0; i< 10; i++) {
	printf("%d ", fibo[i]);
}
printf("\n");

printf("Lisätään listaan Fibonaccin 11. ja 12. luku.\n");

fibo = (int *) realloc(fibo, sizeof(int) * 12);

if (fibo == NULL) {
	perror("Muistin varaaminen epäonnistui!\n");
	exit(1);
}

fibo[10] = 89;
fibo[11] = 144;

printf("Nyt listassa on 12 Fibonaccin lukua, jotka ovat:\n");

for (i = 0; i < 12; i++) {
	printf("%d ", fibo[i]);
}
printf("\n");

printf("Noh, laitetaan listaan vielä Fibonaccin 13., 14. ja 15. luku.\n");

fibo = (int *) realloc(fibo, sizeof(int) * 15);

if (fibo == NULL) {
	perror("Muistin varaaminen epäonnistui!\n");
	exit(1);
}

fibo[12] = 233;
fibo[13] = 377;
fibo[14] = 610;

printf("Nyt listassa on 15 ensimmäistä Fibonaccin lukua, jotka ovat:\n");

for (i = 0; i < 15; i++) {
	printf("%d ", fibo[i]);
}
printf("\n");

free(fibo);

return 0;
}

/*eof*/
