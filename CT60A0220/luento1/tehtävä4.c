#include <stdio.h>

/*Topi Jussinniemi, 18.1.2018, harjoitus 1, tehtävä 4*/

int main(void) {

char merkki[1];
char mjono[20];

printf("Anna merkki: ");
scanf("%s", merkki);
printf("Annoit merkin '%s'.\n", merkki);

printf("Anna korkeintaan 20 merkkiä pitkä merkkijono: ");
scanf("%s", mjono);
printf("Annoit merkkijonon '%s'.\n", mjono);


return 0;
}

/*eof*/
