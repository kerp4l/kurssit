#include <stdio.h>

/*Topi Jussinniemi, 27.1.2018, harjoitus 3, tehtävä 2*/

void kirjoita(void);
void lue(void);

int main(void) {

int valinta;
int lopetus = 0;

printf("Ohjelma tallentaa nimiä tiedostoon.\n");
printf("\n");

while (lopetus != 1) {

	printf("1) Tallenna uusi nimi\n");
	printf("2) Tulosta nimet\n");
	printf("0) Lopeta\n");
	printf("Valitse: ");
	scanf("%d", &valinta);
	printf("\n");
	
	if (valinta == 1) {
		kirjoita();
		printf("\n");
	} else if (valinta == 2) {
		lue();
		printf("\n");
	} else if (valinta == 0) {
		lopetus = 1;
	} else {
		printf("Virheellinen valinta.\n");
	}
}

return 0;
}



void kirjoita(void) {

char nimi[50];
FILE *tiedosto;

tiedosto = fopen("nimet.txt", "a");
printf("Anna tallennettava nimi: ");
scanf("%s", &nimi);
fprintf(tiedosto, "%s\n", nimi);
fclose(tiedosto);
printf("Nimi on tallennettu tiedostoon.\n");

}




void lue(void) {

FILE *tiedosto;
char nimi[50];

tiedosto = fopen("nimet.txt", "r");
printf("Tiedostossa olevat nimet:\n");

while (fgets(nimi, 49, tiedosto) != NULL) {
	printf("%s", nimi);
}
fclose(tiedosto);
}


/*eof*/
