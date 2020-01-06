/*Topi Jussinniemi, 26.2.2018, harjoitus 7, tehtävä 4*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"


int main(void) {

Solmu *pAlku = NULL;
int koko = 0;
int valinta;
int lopeta = 0;
int tempLuku;
int i;
int alku = 1;
int loppu;
int temp;


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
				}
				tulosta(pAlku);
				alku = alku + koko;
			}
			break;
		case 2:
			pAlku = lisaaSolmu(pAlku, loppu);
			tulosta(pAlku);
			koko = koko + 1;
			loppu = loppu + 1;
			break;
		case 3:
			printf("Monenneksi solmuksi alkio lisätään: ");
			scanf("%d", &temp);
			
			if (temp > (koko + 1)) {
				printf("Listassa ei ole näin monta solmua.\n");
			} else if (temp < 0) {
				printf("Anna positiivinen kokonaisluku.\n");
			} else if (temp == (koko + 1)) {
				pAlku = lisaaSolmu(pAlku, loppu);
				loppu = loppu + 1;
				koko = koko + 1;
				tulosta(pAlku);
			} else {
				pAlku = lisaaKeskelle(pAlku, temp, loppu, koko);
				loppu = loppu + 1;
				koko = koko + 1;
				tulosta(pAlku);
			}
			break;
		case 4:
			pAlku = tyhjenna(pAlku);
			koko = 0;
			break;
		case 5:
			printf("Monesko alkio poistetaan: ");
			scanf("%d", &temp);
			
			if (temp < 0) {
				printf("Anna positiivinen kokonaisluku.\n");
			} else if (temp > koko) {
				printf("Listassa ei ole näin montaa alkiota.\n");
			} else {
				pAlku = poistaAlkio(pAlku, temp);
				koko = koko - 1;
				tulosta(pAlku);
			}
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



