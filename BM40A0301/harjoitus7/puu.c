/*
BM40A0301 Tietorakenteet ja algoritmit
Harjoitus 7, tehtävät 3 ja 4
Topi Jussinniemi 0401301
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int luku;
	struct Node *pVasen;
	struct Node *pOikea;
};

typedef struct Node Solmu;

Solmu *lisaaSolmu(Solmu *, int);
Solmu *luoUusiSolmu(int);
Solmu *lisaa(Solmu *, int);
void esijarjestys(Solmu *);
void sisajarjestys(Solmu *);
void jalkijarjestys(Solmu *);
int etsiLuku(Solmu *, int);
void tyhjennaPuu(Solmu *);

int main(void) {

Solmu *pJuuri = NULL;
int valinta, luku;
int lopeta = 0;



while (lopeta != 1) {
	printf("\n");
	printf("1) Lisää binääripuuhun uusi luku\n");
	printf("2) Tulosta binääripuussa olevat luvut (Esijärjestys)\n");
	printf("3) Tulosta binääripuussa olevat luvut (Sisäjärjestys)\n");
	printf("4) Tulosta binääripuussa olevat luvut (Jälkijärjestys)\n");
	printf("5) Tutki onko jokin luku binääripuussa\n");
	printf("0) Lopeta\n");
	printf("Valintasi: ");
	scanf("%d", &valinta);

	switch (valinta) {
		case 0:
			printf("Kiitos ohjelman käytöstä.\n");
			lopeta = 1;
			tyhjennaPuu(pJuuri);
			break;
		case 1:
			printf("Anna binääripuuhun lisättävä luku: ");
			scanf("%d", &luku);
			pJuuri = lisaa(pJuuri, luku);
			break;
		case 2:
			printf("Binääripuussa olevat luvut esijärjestyksessä: ");
			esijarjestys(pJuuri);
			printf("\n");
			break;
		case 3:
			printf("Binääripuussa olevat luvut sisäjärjestyksessä: ");
			sisajarjestys(pJuuri);
			printf("\n");
			break;
		case 4:
			printf("Binääripuussa olevat luvut jälkijärjestyksessä: ");
			jalkijarjestys(pJuuri);
			printf("\n");
			break;
		case 5:
			printf("Anna binääripuusta etsittävä luku: ");
			scanf("%d", &luku);
			int ehto = etsiLuku(pJuuri, luku);
			if (ehto == 0) {
				printf("Luku %d ei ole binääripuussa.\n", luku );
			} else {
				printf("Luku %d on binääripuussa.\n", luku);
			}
			break;
		default:
			printf("Virheellinen valinta! Yritä uudelleen.\n");
			break;
	}
}

return 0;
}

/*Aliohjelmat*/

/*Uuden solmun lisäämisen ensimmäinen osa.*/

Solmu *lisaa(Solmu *pJuuri, int x) {

Solmu *ptr = pJuuri;

if(pJuuri == NULL) {
	pJuuri = luoUusiSolmu(x);
} else {
	ptr = lisaaSolmu(ptr, x);
}

return pJuuri;

}


/*Uuden solmun luominen ja muistin varaaminen.*/

Solmu *luoUusiSolmu(int x) {

Solmu *ptrUusi;

if ( (ptrUusi = (Solmu *) malloc(sizeof(Solmu))) == NULL ) {
	perror("Muistin varaaminen epäonnistui!\n");
	exit(1);
}
ptrUusi->luku = x;
ptrUusi->pVasen = NULL;
ptrUusi->pOikea = NULL;

return ptrUusi;
}

/*Uuden luvun lisääminen oikeean paikkaan puussa.*/

Solmu *lisaaSolmu(Solmu *pJuuri, int x) {

if (pJuuri == NULL) {
	pJuuri = luoUusiSolmu(x);
} else {
	if (pJuuri->luku >= x) {
		pJuuri->pVasen = lisaaSolmu(pJuuri->pVasen, x);
	} else {
		pJuuri->pOikea = lisaaSolmu(pJuuri->pOikea, x);
	}
}
return pJuuri;
}


/*
Seuraat kolme aliohjelmaa ovat piin alkioiden tulostamista varten.
1. Esijärjestys
2. Sisäjärjestys
3. Jälkijärjestys
*/


void esijarjestys(Solmu *pJuuri) {

if (pJuuri == NULL) {
	return;
}
printf("%d ", pJuuri->luku);
esijarjestys(pJuuri->pVasen);
esijarjestys(pJuuri->pOikea);
}



void sisajarjestys(Solmu *pJuuri) {

if (pJuuri == NULL) {
	return;
}
sisajarjestys(pJuuri->pVasen);
printf("%d ", pJuuri->luku);
sisajarjestys(pJuuri->pOikea);
}


void jalkijarjestys(Solmu *pJuuri) {

if (pJuuri == NULL) {
	return;
}
jalkijarjestys(pJuuri->pVasen);
jalkijarjestys(pJuuri->pOikea);
printf("%d ", pJuuri->luku);
}



/*Tutkii onko tietty luku puussa. Jos on palautetaan 1 jos ei ole palautetaan 0.*/

int etsiLuku(Solmu *pJuuri, int x) {

int k = 0;

if (pJuuri->luku == x) {
	k = 1;
} else {
	while ((pJuuri->pVasen != NULL) && (pJuuri->pOikea != NULL)) {
		if (pJuuri->luku > x) {
			pJuuri = pJuuri->pVasen;
		} else {
			pJuuri = pJuuri->pOikea;
		}
	if (pJuuri->luku == x) {
		k = 1;
		break;
	}
}
}

return k;

}

/*Tyhjentää puun luvuista ja vapauttaa muistin.*/

void tyhjennaPuu(Solmu *pJuuri) {

if (pJuuri == NULL) {
		return;
}
tyhjennaPuu(pJuuri->pVasen);
tyhjennaPuu(pJuuri->pOikea);
free(pJuuri);
}


/*eof*/
