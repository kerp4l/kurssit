/*
CT30A3370 Käyttäjärjestelmät ja systeemiohjelmointi
Harjoitustyö, projekti 1, my-cat.c
Topi Jussinniemi 0401301
*/


#include <stdio.h>
#include <stdlib.h>

/*Määritetään vakion MAX avulla tiedostosta luettavan rivin maksimipituus.*/
#define MAX 128

int main(int argc, char *argv[]) {

	int i;	
	char rivi[MAX]; /*Muuttuja tiedostosta luettavaa riviä varten.*/

	/*Tarkistetaan onko annettu riittävästi komentoriviparametreja.*/
	if (argc == 1) {
		exit(0);
	} else {
		for (i = 1; i < argc; i++) {    
			FILE *tiedosto;
			
			/*Tarkistetaan onnisuuko tiedoston avaaminen.*/
			if ((tiedosto = fopen(argv[i], "r")) == NULL) {
				perror("my-cat cannot open file.\n");
				exit(1);
			}

			/*Tiedoston lävitse käyminen.*/
			while (!feof (tiedosto)) {
				if (fgets(rivi, MAX, tiedosto) == NULL) {
					break; /*Lähde: https://stackoverflow.com/questions/21180248/fgets-to-read-line-by-line-in-files/21180478*/
				}
				printf("%s", rivi); /*Tulostetaan tiedostosta luettu rivi.*/
			}
		
		fclose(tiedosto);
		printf("\n");
		}
	}


return 0;
}

/*eof*/
