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
				j = k = 0;
				yht = 1;
				c = rivi[0];

				while ((rivi[j] != '\0') && (rivi[j] != '\n') ) {
					if (c == rivi[j]) {
						k = k + 1;
					} else {
						lisaa_solmu(&pAlku, c, k);
						c = rivi[j];
						k = 1;
						yht = yht + 1;
					}
					j = j + 1;
				}
				lisaa_solmu(&pAlku, c, k);
				rivi_lkm = rivi_lkm + 1;
				pakkaa_rivi(pAlku, yht, &argv[1]);
				pAlku = NULL;
				
			}
			fclose(pakattava);
		}
		FILE *tiedosto2;
		tiedosto2 = fopen(argv[1], "ab");

		if (tiedosto2 == NULL) {
			perror("my-zip cannot open file.\n");
			exit(1);
		}
		fwrite(&rivi_lkm, 4, 1, tiedosto2);
		fclose(tiedosto2);
	}







	return 0;
}


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
	
	fwrite(&n, 4, 1, tiedosto);

	for (i = 0; i < n; i++) {
		a = ptr->lkm;
		b = ptr->kirjain;
		
		fwrite(&a, 4, 1, tiedosto);
		fwrite(&b, 1, 1, tiedosto);

		ptr = ptr->seuraava;
	}
	fwrite(&rivin_vaihto, 1, 1, tiedosto);
	fclose(tiedosto);


	tyhjenna_lista(p);
}





void tyhjenna_lista(solmuosoitin p) {

	if (p == NULL) {
		return;
	}
	tyhjenna_lista(p->seuraava);
	free(p);
}














