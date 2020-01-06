/*Topi Jussinniemi, 11.2.2018, harjoitus 5, tehtävä 3*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct HENKILO {
	char nimi[30];
	int ika;
};

typedef struct HENKILO Henkilo;

void vertaa1(Henkilo h1, Henkilo h2);
Henkilo* kopioi(Henkilo *h1);
void vertaa2(Henkilo *h1, Henkilo *h3);


int main(void) {

Henkilo h1;
Henkilo h2;

printf("Anna ensimmäisen henkilön etunimi: ");
scanf("%s", h1.nimi);
printf("Anna ensimmäisen henkilön ikä: ");
scanf("%d", &h1.ika);
printf("Anna toisen henkilön etunimi: ");
scanf("%s", h2.nimi);
printf("Anna toisen henkilön ikä: ");
scanf("%d", &h2.ika);

vertaa1(h1,h2);

Henkilo *ph1;
ph1 = &h1;

Henkilo *ph3 = kopioi(ph1);

vertaa2(ph1, ph3);

return 0;
}

void vertaa1(Henkilo h1, Henkilo h2) {

int vertailu = strcmp(h1.nimi, h2.nimi);
if ((vertailu < 0) || (h1.ika != h2.ika)) {
	printf("Tietueiden tiedot eivät ole samoja.\n");
} else {
	printf("Tietueiden tiedot ovat samoja.\n");
}
}

Henkilo* kopioi(Henkilo *h1) {

Henkilo *ph3 = (Henkilo *) malloc(sizeof(Henkilo));
strcpy(ph3->nimi, h1->nimi);
ph3->ika = h1->ika;

return ph3;
}

void vertaa2(Henkilo *h1, Henkilo *h3) {

int vertailu = strcmp(h1->nimi, h3->nimi);

if ((vertailu < 0) || (h1->ika != h3->ika)) {
	printf("Tietueiden tiedot eivät ole samoja.\n");
} else {
	printf("Tietueiden tiedot ovat samoja.\n");
}

if (&h1 == &h3) {
	printf("Tietueiden osoitteet ovat samoja.\n");
} else {
	printf("Tietueiden osoitteet eivät ole samoja.\n");
}

free(h3);

printf("Kiitos ohjelman käytöstä.\n");

}



/*eof*/
