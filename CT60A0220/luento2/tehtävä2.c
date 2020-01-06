#include <stdio.h>

/*Topi Jussinniemi, 19.1.2018, harjoitus 2, tehtävä 2*/

int main(void) {

int luku1;
int luku2;
int summa;
int tulo;
int valinta;

printf("Anna kaksi kokonaislukua: ");
scanf("%d %d", &luku1, &luku2);
printf("\n");

printf("Valikko\n");
printf("1) Summaa luvut yhteen.\n");
printf("2) Kerro luvut keskenään.\n");
printf("Valitse: ");
scanf("%d", &valinta);
printf("\n");


if (valinta == 1) {
	summa = luku1 + luku2;
	printf("Luvut laskettiin yhteen. Tulos = %d.\n", summa);
} else if (valinta == 2) {
	tulo = luku1 * luku2;
	printf("Luvut kerrottiin toisillaan. Tulos = %d.\n", tulo);
} else {
	printf("Tuntematon valinta.\n");
}



return 0;
}

/*eof*/
