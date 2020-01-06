/*Topi Jussinniemi, 20.2.2018, harjoitus 6, tehtävä 4*/

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
int tempLuku;
int i;
int alku = 1;
int loppu;


printf("Tämä ohjelma hallitsee listaa ja sen alkioita.\n");

while (lopeta != 1) {
	
	printf("1) Luo lista\n");
	printf("2) Lisää alkio listan loppuun\n");
	printf("3) Lisää alkio listan keskelle\n");
	printf("4) Tyhjennä lista\n");
	printf("5) Poista alkio listasta\n");
	printf("6) Tulosta lista\n");
	printf("0) Lopeta\n");
	
	printf("Anna valintasi: ");
	scanf("%d", &valinta);
	
	switch (valinta) {
		case 1:
			printf("Anna listan pituus: ");
			scanf("%d", &tempLuku);
			
			if (tempLuku < 0) {
				printf("Listan pituus ei voi olla negatiivinen.\n");
			} else {
				koko = tempLuku;
				pAlku = tyhjenna(pAlku);
				
				loppu = alku + koko;
				for (i = alku; i < loppu; i++) {
					pAlku = lisaaSolmu(pAlku, i);
					printf(" %d", i);
				}
				alku = alku + koko;
				printf("\n");
			}
			break;
		case 2:
			pAlku = lisaaSolmu(pAlku, loppu);
			tulosta(pAlku);
			koko = koko + 1;
			loppu = loppu + 1;
			break;
		case 3:
			break;
		case 4:
			pAlku = tyhjenna(pAlku);
			koko = 0;
			break;
		case 5:
			break;
		case 6:
			tulosta(pAlku);
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
