#include <stdio.h>
#include <stdlib.h>


struct Node {
	int luku;
	struct  Node *pSeuraava;
};

typedef struct Node Solmu;

Solmu *liisaaSolmu(Solmu *, int);
void tyhjennaLista(Solmu *);
void tulostaLista(Solmu *);


int main(void) {


Solmu *pAlku = NULL;

int valinta, luku;
int lopeta = 0;

printf("Ohjelma lisää antamasi luvut listaan ja tulostaa ne halutessasi.\n");
int k = 50; pAlku = lisaaSolmu(pAlku, k);


while (lopeta != 1) {
	printf("1) Lisää uusi luku listaan\n");
	printf("2) Tulosta lista\n");
	printf("3) Poista alkio\n");
	printf("0) Lopeta\n");
	printf("Valintasi: ");
	scanf("%d", &valinta);

	switch (valinta) {
		case 0:
			printf("Ohjelma lopetetaan.\n");
			tyhjennaLista(pAlku);
			tulostaLista(pAlku);
			lopeta = 1;
		case 1:
			printf("Anna listaan lisättävä luku: ");
			scanf("%d", &luku);
		default:
			printf("Virheellinen syöte!\n");
	}
	
}


return 0;
}

/*Aliohjelmat*/

Solmu *lisaaSolmu(Solmu *pAlku, int x) {

Solmu *ptr, *ptrUusi;

if ((ptrUusi = (Solmu *) malloc(sizeof(Solmu))) == NULL) {
	printf("Muistin varaaminen epäonnistui. Ohjelma suljetaan.\n");
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


void tyhjennaLista(Solmu *pAlku) {

Solmu *ptr = pAlku;

while (ptr != NULL) {
	pAlku = ptr->pSeuraava;
	free(ptr);
	ptr = pAlku;
}
}

void tulostaLista(Solmu *pAlku) {

Solmu *ptr = pAlku;

while (ptr != NULL) {
	printf(" %d", ptr->luku);
	ptr = ptr->pSeuraava;
}
printf("\n");

}

















