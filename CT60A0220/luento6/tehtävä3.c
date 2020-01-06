/*Topi Jussinniemi, 20.2.2018, harjoitus 6, tehtä*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	int luku;
	struct Node *pNext;
};

typedef struct Node Solmu;

Solmu *lisaaSolmu(Solmu *pAlku, int i);
void tulosta(Solmu *pAlku);
Solmu *tyhjenna(Solmu *pAlku);


int main(void) {

Solmu *pAlku = NULL;
int koko = 0;
int valinta;
int lopeta = 0;
int temp;
int i;

while (lopeta != 1) {
	
	printf("1) Tulosta listan alkiot\n");
	printf("2) Muuta listan pituutta\n");
	printf("0) Lopeta\n");
	printf("Anna valintasi: ");
	scanf("%d", &valinta);
	
	switch(valinta) {
		case 1:
			if (koko == 0) {
				printf("Lista on tyhjä.\n");
			} else {
				tulosta(pAlku);
			}
			break;
		case 2:
			printf("Anna listan uusi pituus: ");
			scanf("%d", &temp);;
			if (temp < 0) {
				printf("Listan pituus ei voi olla negatiivinen.\n");
			} else {
				koko = temp;
				pAlku = tyhjenna(pAlku);
				for (i = 0; i < koko; i++) {
					pAlku = lisaaSolmu(pAlku, i);
				}
			}
			break;
		case 0:
			printf("Kiitos ohjelman käytöstä.\n");
			lopeta = 1;
			break;
		default:
			printf("Tuntematon valinta.\n");
			break;
	}
}


return 0;
}


Solmu *lisaaSolmu(Solmu *pAlku, int i) {
Solmu *ptr, *ptrUusi;

if ((ptrUusi = (Solmu *) malloc(sizeof(Solmu))) == NULL) {
	printf("Muistin varaaminen epäonnistui.\n");
	exit(1);
}
ptrUusi->luku = i;
ptrUusi->pNext = NULL;

if (pAlku == NULL) {
	pAlku = ptrUusi;
} else {
	ptr = pAlku;
	while (ptr->pNext != NULL) {
		ptr = ptr->pNext;
	}
	ptr->pNext = ptrUusi;
}
return pAlku;
}

void tulosta(Solmu *pAlku) {

Solmu *ptr = pAlku;

printf("Listassa on seuraavat luvut:");

while (ptr != NULL) {
	printf(" %d", ptr->luku);
	ptr = ptr->pNext;
}
printf("\n");
}

Solmu *tyhjenna(Solmu *pAlku) {

Solmu *ptr = pAlku;

while (ptr != NULL) {
	pAlku = ptr->pNext;
	free(ptr);
	ptr = pAlku;
}
return pAlku;

}


/*eof*/
