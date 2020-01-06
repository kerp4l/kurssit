/*****************************************************************************/
/* CT60A0220 C-ohjelmoinnin ja testauksen periaatteet 
 * Tekijä: Topi Jussinniemi
 * Opiskelijanumero: 0401301
 * Päivämäärä: 28.2.2018
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "nimilista.h"

/*****************************************************************************/
/* NIMITIEDOT SISÄLTÄVÄN TIEDOSTON LUKEMINEN */

NimiSolmu *lueTiedosto(NimiSolmu *pAlku, char tiedostoNimi[]) {

FILE *tiedosto;
char rivi[50], *p1, *p2;
int riviLkm = -1;

if ((tiedosto = fopen(tiedostoNimi, "r")) == NULL) {
	perror("Tiedoston avaaminen epäonnistui");
	exit(1);
}

while (fgets(rivi, 50, tiedosto) != NULL) {
	if (riviLkm > -1) {
		p1 = strtok(rivi, ";");
		p2 = strtok(NULL, ";");
		pAlku = lisaaNimiSolmu(pAlku, p1, p2);
	}
	riviLkm = riviLkm + 1;
}
fclose(tiedosto);

printf("Luetaan tiedosto %s.\n", tiedostoNimi);
printf("Tiedosto %s luettu, %d nimiriviä.\n", tiedostoNimi, riviLkm);

return pAlku;
}

/*****************************************************************************/
/* UUDEN SOLMUN LISÄÄMINEN LINKITETTYYN NIMILISTAAN */

NimiSolmu *lisaaNimiSolmu(NimiSolmu *pAlku, char *pNimi, char *pLkm) {

NimiSolmu *ptr, *ptrUusi;

if ((ptrUusi = (NimiSolmu *) malloc(sizeof(NimiSolmu))) == NULL) {
	perror("Muistin varaaminen epäonnistui");
	exit(1);
}

strcpy(ptrUusi->nimi, pNimi);
ptrUusi->lkm = atol(pLkm);
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

/*****************************************************************************/
/* NIMILISTAN TYHJENTÄMINEN */

NimiSolmu *tyhjennaNimilista(NimiSolmu *pAlku) {

NimiSolmu *ptr = pAlku;

while (ptr != NULL) {
	pAlku = ptr->pNext;
	free(ptr);
	ptr = pAlku;
}

return pAlku;

}

/*****************************************************************************/
/* NIMILISTASSA OLEVIEN NIMITIETOJEN LUKUMÄÄRÄN LASKEMINEN */

long int laskeNimilistanPituus(NimiSolmu *pAlku) {

long int pituus = 0;
NimiSolmu *ptr = pAlku;

while (ptr != NULL) {
	ptr = ptr->pNext;
	pituus = pituus + 1;
}
return pituus;
}


/*****************************************************************************/
/* NIMILISTAN PISIMMÄN NIMEN PITUUDEN SELVITTÄMINEN */

int maxPituusNimilista(NimiSolmu *pAlku) {

int max = 0;
NimiSolmu *ptr = pAlku;

while (ptr != NULL) {
	if (strlen(ptr->nimi) > max) {
		max = strlen(ptr->nimi);
	}
ptr = ptr->pNext;
}
return max;
}


/*****************************************************************************/
/* NIMILISTAN LYHIMMÄN NIMEN PITUUDEN SELVITTÄMINEN */

int minPituusNimilista(NimiSolmu *pAlku) {

int min = 100;
NimiSolmu *ptr = pAlku;

while (ptr != NULL) {
	if (strlen(ptr->nimi) < min) {
		min = strlen(ptr->nimi);
	}
ptr = ptr->pNext;
}
return min;
}

/*****************************************************************************/
/* NIMILISTASSA OLEVIEN NIMIEN PITUUKSIEN KESKIARVON LASKEMINEN */

int kaPituusNimilista(NimiSolmu *pAlku, long int lkm) {

long int total = 0;
int keskiarvo;
NimiSolmu *ptr = pAlku;

while (ptr != NULL) {
	total = total + strlen(ptr->nimi);
	ptr = ptr->pNext;
}
keskiarvo = total / lkm;
return keskiarvo;
}
/*****************************************************************************/
/* NIMILISTAN VARAAMAN MUISTIN MÄÄRÄN LASKEMINEN KILOTAVUINA */

int varattuMuistiNimilistaKB(int lkm) {

long int tavua = lkm * sizeof(NimiSolmu);
int kiloTavua = tavua / 1000;

return kiloTavua;
}


/*****************************************************************************/
/* KAYTÖSSÄ OLEVAN MUISTIN LASKEMINEN PROSENTTEINA */

int kaytettyMuistiNimilista(NimiSolmu *pAlku, long int lkm) {

long int varattuMuisti = lkm * sizeof(NimiSolmu);
long int kayttamatonMuisti = 0;
int kaytettyMuisti;
NimiSolmu *ptr = pAlku;

while (ptr != NULL) {
	kayttamatonMuisti = kayttamatonMuisti + sizeof(char)*(29 - strlen(ptr->nimi));
	ptr = ptr->pNext;
}
double temp1 = varattuMuisti;
double temp2 = kayttamatonMuisti;

kaytettyMuisti = ceil(((temp1-temp2)/temp1) * 100);

return kaytettyMuisti;
}


/*****************************************************************************/
/* eof */
