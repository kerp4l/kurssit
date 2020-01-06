/*Topi Jussinniemi, 26.2.2018, harjoitus 7, tehtävä 4*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"



Solmu *lisaaSolmu(Solmu *pAlku, int luku) {

Solmu *ptr, *ptrUusi;

if ((ptrUusi = (Solmu *) malloc(sizeof(Solmu))) == NULL) {
	printf("Muistin varaaminen epäonnistui. Ohjelma suljetaan.\n");
	exit(1);
}
ptrUusi->luku = luku;
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


while (ptr != NULL) {
	printf("%d ", ptr->luku);
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


Solmu *lisaaKeskelle(Solmu *pAlku, int paikka, int luku, int koko) {

int i;
Solmu *ptr, *ptrUusi, *ptrSeuraava, *ptrEdellinen;

if ((ptrUusi = (Solmu *) malloc(sizeof(Solmu))) == NULL ) {
	printf("MUISTIN VARAAMINEN EPÄONNOSTUI! OHJELMA SULJETAAN.\n");
	exit(1);
}
ptrUusi->luku = luku;

if (paikka == 1) {
	ptrUusi->pNext = pAlku;
	pAlku = ptrUusi;
} else {
	ptr = pAlku;
	for (i = 1; i < paikka; i++) {
		ptrSeuraava = ptr->pNext;
		ptrEdellinen = ptr;
		ptr = ptrSeuraava;
	}
	ptrEdellinen->pNext = ptrUusi;
	ptrUusi->pNext = ptrSeuraava;
}

return pAlku;
}


Solmu *poistaAlkio(Solmu *pAlku, int paikka) {

int i;
Solmu *ptr, *ptrSeuraava, *ptrPoista, *ptrTemp;

if (paikka == 1) {
	ptrSeuraava = pAlku->pNext;
	ptr = pAlku;
	free(ptr);
	pAlku = ptrSeuraava;
} else {
	ptr = pAlku;
	for (i = 1; i < paikka; i++) {
		ptrPoista = ptr->pNext;
		ptrSeuraava = ptrPoista->pNext;
		ptrTemp = ptr;
		ptr = ptr->pNext;
	}
	ptrTemp->pNext = ptrSeuraava;
	free(ptrPoista);
}
return pAlku;
}


