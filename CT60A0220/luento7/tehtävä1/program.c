/*Topi Jussinniemi, 25.2.2018, harjoitus 7m tehtävä 1*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "muisti.h"
#include "io.h"

int main(void) {

int numerot;
int lisanumerot;
int *lista1;
int *lista2;

printf("Lottoarvonta\n");
printf("Kuinka monta numeroa arvotaan: ");
scanf("%d", &numerot);
printf("Kuinka monta lisänumeroa arvotaan: ");
scanf("%d", &lisanumerot);

lista1 = varaaMuistiaNumeroille(numerot);
lista2 = varaaMuistiaNumeroille(lisanumerot);

arvoNumerot(lista1, numerot);
arvoNumerot(lista2, lisanumerot);

printf("Arvottiin seuraavat numerot ja lisänumerot.\n");
printf("Numerot:");
tulostaNumerot(lista1, numerot);
printf("Lisänumerot:");
tulostaNumerot(lista2, lisanumerot);



vapautaMuisti(lista1);
vapautaMuisti(lista2);

return 0;
}
