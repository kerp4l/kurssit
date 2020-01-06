/*
CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi
Harjoitustyö, projekti 1, my-zip.c
Topi Jussinniemi 0401301
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 512 /*Maksimi pituus tiedostosta luettavalle riville.*/

/*Linkitetyn listan solmu.*/
struct Node {
	char kirjain;
	int lkm;
	struct Node *seuraava;
};

typedef struct Node Solmu;
typedef Solmu *solmuosoitin;

void lisaa_solmu(solmuosoitin *, char, int);
void pakkaa_rivi(solmuosoitin, int, char *t[]);
void tyhjenna_lista(solmuosoitin);


int main(int argc, char *argv[]) {
	
	char rivi[MAX];
	int i, j, k, yht;
	int rivi_lkm = 0;
	char c;
	solmuosoitin pAlku = NULL;
	
	if (argc < 3) { /*Ei anneta komentoriviparametreja*/
		printf("my-zip: file1 [file2 ...]\n");
		exit(1);
	} else {
		for (i = 2; i < argc; i++) {
			FILE *pakattava;
			pakattava = fopen(argv[i], "r");

			if (pakattava == NULL)  {
				perror("my-zip cannot open file.\n");
				exit(1);
			}
			while (!feof (pakattava)) {
				if (fgets(rivi, MAX, pakattava) == NULL) {
					break;
				}
				/*Laskurien alustaminen.*/
				j = k = 0; /*j = tutkittavan merkkijonon indeksi, k = montako  tiettyä merkkiä koodataan*/
				yht = 1;
				c = rivi[0]; /*yht = montako erilaista merkkien koodausta rivi sisältää*/

				/*silmukka pyörii kunnes saavutaan tiedostosta luetun rivin päähän.*/
				while ((rivi[j] != '\0') && (rivi[j] != '\n') ) {
					if (c == rivi[j]) { /*Tutkittava merkkijonon merkki on sama, kuin edellinenkin.*/
						k = k + 1;
					} else { /*Tutkittava merkkijonon merkki ei ole sama, kuin edellinen.*/
						lisaa_solmu(&pAlku, c, k); /*Päivitetään linkitettyyn listaan uusi koodattava merkki ja sen lukumäärä.*/
						c = rivi[j];
						k = 1; /*Uusi koodattava merkki.*/
						yht = yht + 1;
					}
					j = j + 1;
				}
				/*Rivi on saatu käytyä lävitse*/
				lisaa_solmu(&pAlku, c, k);
				rivi_lkm = rivi_lkm + 1; /*Kasvatetaan läpi käytyjen rivien lukumäärää yhdellä.*/
				pakkaa_rivi(pAlku, yht, &argv[1]); /*Kirjoitetaan pakattu rivi binääritiedostoon.*/
				pAlku = NULL;
				
			}
			fclose(pakattava);
		}
		/*Kaikki pakattavat tiedostot on käyty lävitse.*/
		FILE *tiedosto2;
		tiedosto2 = fopen(argv[1], "ab");

		if (tiedosto2 == NULL) {
			perror("my-zip cannot open file.\n");
			exit(1);
		}
		/*Kirjoitetaan pakatun tiedoston loppuun kokonaisluku, mikä kertoo montako riviä tiedosto sisältää.*/
		fwrite(&rivi_lkm, 4, 1, tiedosto2);
		fclose(tiedosto2);
	}







	return 0;
}


/*Ali ohjelma, mikä lisää uuden solmun linkitettyyn listaan.*/
/*Ottaa parametreiksi osoittimen listan alkuun, koodattavan merkin ja niiden lukumäärän.*/

void lisaa_solmu(solmuosoitin *p, char a, int b) {

	solmuosoitin ptr, ptrUusi;
	
	ptrUusi = (solmuosoitin) malloc(sizeof(Solmu));
	if (ptrUusi == NULL) {
		perror("Memory allocation failed.\n");
		exit(1);
	}
	ptrUusi->kirjain = a;
	ptrUusi->lkm = b;
	ptrUusi->seuraava = NULL;
	
	if((*p) == NULL) {
		*p = ptrUusi;
	} else {
		ptr = *p;
		while (ptr->seuraava != NULL) {
			ptr = ptr->seuraava;
		}
		ptr->seuraava = ptrUusi;
	}

}


/*Aliohjelma, mikä kirjoittaa binääritiedostooon yhden rivin.*/
/*Aliohjelma ottaa parametreiksi osoittimen linkitetyn listan alkuun, joka sisältää riville tehtävät  erilaiset koodaukset.*/
/*Lisäksi parametreiksi annetaan kokonaisluku, mikä kertoo montako erilaista koodausta rivillä on sekä   tiedostonimi merkkijonona*/

void pakkaa_rivi(solmuosoitin p, int n, char *tiedosto_nimi[]) {

	solmuosoitin ptr = p;
	int i, a;
	char b;
	char rivin_vaihto = '\n';

	FILE *tiedosto;
	tiedosto = fopen(*tiedosto_nimi, "ab");
	
	if (tiedosto == NULL) {
		perror("my-xip cannot open file.\n");
		exit(1);
	}
	
	/*Ensimmäiseksi kirjoitetaan rivin alkuun tieto siitä montako erilaista koodausta rivi sisältää.*/
	fwrite(&n, 4, 1, tiedosto);

	/*Kirjoitetaan linkitetyssä listassa olevat koodattavat merkit ja niiden lukumäärät binääritiedostoon.*/
	for (i = 0; i < n; i++) {
		a = ptr->lkm;
		b = ptr->kirjain;
		
		fwrite(&a, 4, 1, tiedosto);
		fwrite(&b, 1, 1, tiedosto);

		ptr = ptr->seuraava;
	}
	/*Viimeiseksi kirjoitetaan rivin loppuun rivinvaihtomerkki.*/
	fwrite(&rivin_vaihto, 1, 1, tiedosto);
	fclose(tiedosto);

	/*Tyhjennetään linkitetty lista seuraavaa riviä varten.*/
	tyhjenna_lista(p);
}



/*Aliohjelma linkitetyn listan tyhjentämiseen ja muistin vapauttamiseen.*/

void tyhjenna_lista(solmuosoitin p) {

	if (p == NULL) {
		return;
	}
	tyhjenna_lista(p->seuraava);
	free(p);
}


/*eof*/
