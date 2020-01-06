/*
CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi
Harjoitustyö, projekti 1, my-unzip.c
Topi Jussinniemi 0401301
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char *argv[]) {
	
	int i, j, k, n, rivi_lkm, lkm, t;
	char merkki;

	if (argc == 1) { /*Ei ole annettu komentoriviparametreja.*/
		printf("my-unzip: file1 [file2 ..]\n");
		exit(1);
	} else {
		for (i = 1; i < argc; i++) {
			
			FILE *tiedosto;
			tiedosto = fopen(argv[i], "rb");
			
			if (tiedosto == NULL) {
				perror("my-unzip cannot open file.\n");
				exit(1);
			}
			
			fseek(tiedosto, -4, SEEK_END); /*Asetetaan tiedosto-osoitin osoittamaan  tiedoston neljän viimeisen tavun kohdalle.*/
			/*Luetaan tieto siitä montako riviä purettavassa tiedostossa on Kokonaisluku on tallennettu tiedoston viimeiseen neljään tavuun.*/
			fread(&rivi_lkm, 4, 1, tiedosto);
			fseek(tiedosto, 0, SEEK_SET); /*Siirretään tiedosto-osoitin osoittamaan taas tiedoston alkuun-*/
			
			for (j = 0; j < rivi_lkm; j++) { /*Kokonaisen rivin käsittely.*/

				/*Luetaan rivin alusta kokonaisluku, mikä ilmoittaa montako koodausta ko. rivillä on.*/
				fread(&n, 4, 1, tiedosto);

				for (k = 0; k < n; k++) {

					/*Luetaan purettava merkki ja niiden lukumäärä.*/
					fread(&lkm, 4, 1, tiedosto);
					fread(&merkki, 1, 1, tiedosto);
					
					for(t = 0; t < lkm; t++) { /*Tulostetaan merkki tarvittavan monta kertaa.*/
						printf("%c", merkki);
					}
					
				}
				/*Luetaan ja tulostetaan vielä rivin viimeinen merkki, mikä on rivinvaihtomerkki.*/
				fread(&merkki, 1, 1, tiedosto);
				printf("%c", merkki);
			}

			fclose(tiedosto);
		}
		
	}

	return 0;
}

/*eof*/
