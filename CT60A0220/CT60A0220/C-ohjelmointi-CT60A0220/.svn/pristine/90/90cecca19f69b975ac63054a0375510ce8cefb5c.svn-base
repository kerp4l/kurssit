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
#include "tuloslista.h"

/*****************************************************************************/
/* UUDEN SOLMUN LISÄÄMINEN LINKITETTYYN TULOSLISTAAN */

TulosSolmu *lisaaTulosSolmu(TulosSolmu *pAlku, char nimi[], long int lkm, int max, int min, int keskiarvo, int varattu, int kaytetty) {

TulosSolmu *ptr, *ptrUusi;

if ((ptrUusi = (TulosSolmu *) malloc(sizeof(TulosSolmu))) == NULL) {
	perror("Muistinvaraaminen epäonnistui");
	exit(1);
}

strcpy(ptrUusi->nimi, nimi);
ptrUusi->lkm = lkm;
ptrUusi->max = max;
ptrUusi->min = min;
ptrUusi->keskiarvo = keskiarvo;
ptrUusi->varattuMuisti = varattu;
ptrUusi->kaytettyMuisti = kaytetty;
ptrUusi->pNext = NULL;

printf("Datasetti Nimiä MinPit MaxPit KA Muistinkäyttö\n");
printf("%s", nimi);
printf("	%li", lkm);
printf("	%d", min);
printf("	%d", max);
printf("	%d", keskiarvo);
printf("	%d kB / %d %%\n", varattu, kaytetty);

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
/* tULOSLISTAN TYHJENTÄMINEN */

TulosSolmu *tyhjennaTuloslista(TulosSolmu *pAlku) {

TulosSolmu *ptr = pAlku;

while (ptr != NULL) {
	pAlku = ptr->pNext;
	free(ptr);
	ptr = pAlku;
}
return pAlku;
}


/*****************************************************************************/
/* TULOSLISTAN SISÄLLÖN TULOSTAMINEN NÄYTÖLLE */

void tulostaTuloslista(TulosSolmu *pAlku) {

TulosSolmu *ptr = pAlku;

printf("Datasetti Nimiä MinPit MaxPit KA Muistinkäyttö\n");

while (ptr != NULL) {
	printf("%s", ptr->nimi);
	printf("	%li", ptr->lkm);
	printf("	%d", ptr->min);
	printf("	%d", ptr->max);
	printf("	%d", ptr->keskiarvo);
	printf("	%d kB / %d %%\n", ptr->varattuMuisti, ptr->kaytettyMuisti);
	
	ptr = ptr->pNext;
}
}

/*****************************************************************************/
/* TULOSLISTAN SISÄLLÖN TALLENTAMINEN TIEDOSTOON */

void tallennaTuloslista(TulosSolmu *pAlku, char tiedostoNimi[]) {

TulosSolmu *ptr = pAlku;
FILE *tiedosto;

if ((tiedosto = fopen(tiedostoNimi, "a")) == NULL) {
	perror("Tiedoston avaaminen epäonnistui");
	exit(1);
}

fprintf(tiedosto, "Datasetti Nimiä MinPit MaxPit KA Muistinkäyttö\n");

while (ptr != NULL) {
	fprintf(tiedosto, "%s", ptr->nimi);
	fprintf(tiedosto, "	%li", ptr->lkm);
	fprintf(tiedosto, "	%d", ptr->min);
	fprintf(tiedosto, "	%d", ptr->max);
	fprintf(tiedosto, "	%d", ptr->keskiarvo);
	fprintf(tiedosto, "	%d kB / %d %%\n", ptr->varattuMuisti, ptr->kaytettyMuisti);
	
	ptr = ptr->pNext;
}

printf("Tiedosto tallennettu.\n");

fclose(tiedosto);
}

/*****************************************************************************/
/* eof */
