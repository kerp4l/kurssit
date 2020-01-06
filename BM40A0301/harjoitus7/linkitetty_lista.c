/*
BM40A0301 Tietorakenteet ja algoritmit
Harjoitus 7, tehtävä 2
Topi Jussinniemi 0401301
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int luku;
	struct Node *pSeuraava;
};

typedef struct Node Solmu;

Solmu *lisaaSolmu(Solmu *, int);
void tulostaLista(Solmu *);
void tyhjennaLista(Solmu *);
int etsiLuku(Solmu *, int);
Solmu *poistaSolmu(Solmu *, int);

int main(void) {

Solmu *pAlku = NULL;
int valinta, luku;
int lopeta = 0;

while (lopeta != 1) {
	printf("1) Lisää luku listaan\n");
	printf("2) Poista luku listasta\n");
	printf("3) Tulosta lista\n");
	printf("0) Lopeta\n");
	printf("Valintasi: ");
	scanf("%d", &valinta);

	switch (valinta) {
		case 0:
			printf("Kiitos ohjelman käytöstä!\n");
			tyhjennaLista(pAlku);
			lopeta = 1;
			break;
		case 1:
			printf("Anna listaan lisättävä luku: ");
			scanf("%d", &luku);
			pAlku = lisaaSolmu(pAlku, luku);
			break;
		case 2:
			printf("Anna listasta poistettava luku: ");
			scanf("%d", &luku);
			int ehto = etsiLuku(pAlku, luku);
			if (ehto == 0) {
				printf("Luku %d ei ole listassa.\n", luku);
			} else {
				pAlku = poistaSolmu(pAlku, luku);
				printf("Luku %d poistettiin listasta.\n", luku);
			}
			break;
		case 3:
			printf("Listassa on seuraavat luvut: ");
			tulostaLista(pAlku);
			break;
		default:
			printf("Virheellinen valinta! Yritä uudelleen.\n");
			break;
	}
	printf("\n");
}

return 0;
}

/*Aliohjelmat*/

/*Uuden solmun lisääminen linkitettyyn listaan.*/

Solmu *lisaaSolmu(Solmu *pAlku, int x) {

Solmu *ptr, *ptrUusi;

if ((ptrUusi = (Solmu *) malloc(sizeof(Solmu))) == NULL) {
	printf("Muistin varaaminen eoäonnistui. Ohjelma suljetaan.\n");
	exit(1);
}

ptrUusi->luku = x;
ptrUusi->pSeuraava = NULL;

if (pAlku == NULL) {
	pAlku = ptrUusi;
} else {
	ptr = pAlku;
	while (ptr->pSeuraava != NULL) {
		ptr = ptr->pSeuraava;
	}
	ptr->pSeuraava = ptrUusi;
}

return pAlku;
}

/*Listan lukujen tulostaminen.*/

void tulostaLista(Solmu *pAlku) {

Solmu *ptr = pAlku;

while (ptr != NULL) {
	printf("%d ", ptr->luku);
	ptr = ptr->pSeuraava;
}
printf("\n");
}

/*Listan tyhjentäminen ja muistin vapauttaminen.*/

void tyhjennaLista(Solmu *pAlku) {

Solmu *ptr = pAlku;

while (ptr != NULL) {
	pAlku = ptr->pSeuraava;
	free(ptr);
	ptr = pAlku;
}
}

/*Tietyn luvun etsiminen listasta. Palauttaa 0 jos luku ei ole listassa ja 1 jos luku on listassa*/

int etsiLuku(Solmu *pAlku, int x) {

Solmu *ptr = pAlku;
int k = 0;

while (ptr != NULL) {
	if (ptr->luku == x) {
		k = 1;
	}
	ptr = ptr->pSeuraava;
}
return k;
}

/*Tietyn luvun poistaminen listasta.*/

Solmu *poistaSolmu(Solmu *pAlku, int x) {

Solmu *ptr = pAlku;
Solmu *p1, *p2;

if (pAlku->luku == x) {
	pAlku = ptr->pSeuraava;
	free(ptr);
} else {

	while (ptr->luku != x) {
		p1 = ptr;
		ptr = ptr->pSeuraava;
	}
	if (ptr->pSeuraava == NULL) {
		p1->pSeuraava = NULL;
		free(ptr);
	} else {
		p2 = ptr->pSeuraava;
		p1->pSeuraava = p2;
		free(ptr);
	}
	
}

return pAlku;

}


/*eof*/
