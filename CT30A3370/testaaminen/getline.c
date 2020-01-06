/*
CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi
Harjoitustyö, projekti 1, my-grep.c
Topi Jussinniemi 0401301
*/
/*
LÄHTEET:
1. https://c-for-dummies.com/blog/?p=1112
2. https://www.youtube.com/watch?v=WLS6JyOZmIA
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

	char *puskuri;
	size_t puskuri_koko = 32;
	char *vertailu;
	int i;

	if (argc == 1) { /*KKomentoriviparametreja ei ole annettu.*/

		printf("my-grep: searchterm [file...]\n");
		printf("\n");
		exit(1);

	} else if (argc == 2){ /*Hakeminen käyttäjän antamasta syötteestä.*/
		
		puskuri = (char *) malloc(puskuri_koko*sizeof(char));
		
		if (puskuri == NULL) {
			perror("Memory allocation failed!\n");
		}
		
		getline(&puskuri, &puskuri_koko, stdin); /*Lähde 1. Luetaan käyttäjän antama syöte.*/
		vertailu = strstr(puskuri, argv[1]); /*Lähde 2*/
		
		/*Tutkitaan onko hakusana annetussa syötteessä.*/
		if (vertailu != NULL) {
			printf("%s", puskuri);
		}
		
	} else { /*Etsiminen tiedostoista.*/
		
		for (i = 2; i < argc; i++) {
			
			FILE *tiedosto;
			tiedosto = fopen(argv[i], "r");
			
			if (tiedosto == NULL) {
				perror("my-grep cannot open file.\n");
				exit(1);
			}




			
			while (!feof (tiedosto)) {
				
				puskuri = (char *) malloc(puskuri_koko*sizeof(char));
				
				if (puskuri == NULL) {
					perror("Memory allocation failed!\n");
					exit(1);
				}


		if(-1 == getline(&puskuri, &puskuri_koko, tiedosto)) {
			break;
		}


			getline(&puskuri, &puskuri_koko, tiedosto); /*Luetaan tiedostosta rivi.*/
			vertailu = strstr(puskuri, argv[1]);
			
			if (vertailu != NULL) {
				printf("%s", puskuri);
			}
			free(puskuri);
			}
		fclose(tiedosto);
		}
		
	}


	return 0;
}

/*eof*/
