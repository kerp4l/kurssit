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
#include "tuloslista.h"

int main(void) {

int lopetus = 0;
int valinta;
char tiedostoNimi[30];
char dataNimi[50];
NimiSolmu *pAlkuNimi = NULL;
TulosSolmu *pAlkuTulos = NULL;
long int lkmNimi;
int maxNimi;
int minNimi;
int kaNimi;
int varattuMuistiKB;
int kaytettyMuisti;


printf("Tämä ohjelma tutkii nimitietoja sisältäviä tiedostoja.\n");

while(lopetus != 1) {
	printf("1) Lue nimitiedosto\n");
	printf("2) Tulosta listassa olevat tiedot\n");
	printf("3) Analysoi tiedot\n");
	printf("4) Tulosta kaikki tulostiedot\n");
	printf("5) Tallenna kaikki tulostiedot tiedostoon\n");
	printf("6) Tyhjennä tuloslista\n");
	printf("0) Lopeta\n");
	
	printf("Anna valintasi: ");
	scanf("%d", &valinta);
	
	switch (valinta) {
		case 1:
			printf("Anna luettavan tiedoston nimi: ");
			scanf("%s", tiedostoNimi);
			
			if (pAlkuNimi != NULL) {
				printf("Poistetaan aiemmat tiedot ja luetaan uudet.\n");
				pAlkuNimi = tyhjennaNimilista(pAlkuNimi);
			}
			
			pAlkuNimi = lueTiedosto(pAlkuNimi, tiedostoNimi);
			break;
		case 2:
			break;
		case 3:
			printf("Anna analysoitavalle datasetille nimi: ");
			scanf("%s", dataNimi);
			printf("Analysoidaan listassa olevat tiedot.\n");
			
			
			lkmNimi = laskeNimilistanPituus(pAlkuNimi);
			maxNimi = maxPituusNimilista(pAlkuNimi);
			minNimi = minPituusNimilista(pAlkuNimi);
			kaNimi = kaPituusNimilista(pAlkuNimi, lkmNimi);
			varattuMuistiKB = varattuMuistiNimilistaKB(lkmNimi);
			kaytettyMuisti = kaytettyMuistiNimilista(pAlkuNimi, lkmNimi);
			pAlkuTulos = lisaaTulosSolmu(pAlkuTulos, dataNimi, lkmNimi, maxNimi, minNimi, kaNimi, varattuMuistiKB, kaytettyMuisti);
			break;
		case 4:
			tulostaTuloslista(pAlkuTulos);
			break;
		case 5:
			printf("Anna tallennettavan tulostiedoston nimi: ");
			scanf("%s", tiedostoNimi);
			tallennaTuloslista(pAlkuTulos, tiedostoNimi);
			break;
		case 6:
			pAlkuTulos = tyhjennaTuloslista(pAlkuTulos);
			printf("Tuloslista tyhjennetty.\n");
			break;
		case 0:
			printf("Kiitos ohjelman käytöstä.\n");
			lopetus = 1;
			pAlkuNimi = tyhjennaNimilista(pAlkuNimi);
			pAlkuTulos = tyhjennaTuloslista(pAlkuTulos);
			break;
		default:
			printf("Tuntematon valinta.\n");
			break;
	}
}




return 0;
}

/*****************************************************************************/
/* eof */
