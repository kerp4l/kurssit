#include <stdio.h>
#include <string.h>

/*Topi Jussinniemi, 19.1.2018, harjoitus 2, tehtävä 5*/

int main(void) {

int valinta;
int lopeta = 0;
int koko;
char mjono[200] = "";
char merkki[1];
char tyhja[200] = "";
char temp[0];

	
while (lopeta != 1) {

	printf("\n");
	printf("Valikko\n");
	printf("1) Lisää uusi merkki\n");
	printf("2) Tyhjennä merkkijono\n");
	printf("3) Tulosta merkkijono\n");
	printf("0) Lopeta\n");
	printf("Valintasi: ");
	scanf("%d", &valinta);
	printf("\n");
	
	koko = strlen(mjono);	


	switch (valinta) {
		case 1:
			if (koko >= 200) {
				printf("Merkkijono on täynnä.\n");
			} else {
				printf("Anna jokin merkki: ");
				scanf("%s", merkki);
				temp[0] = merkki[0];
				mjono[koko] = temp[0];
				mjono[koko+1] = '\0';
			}
			break;
		case 2:
			if (koko == 0) {
				printf("Merkkijono on tyhjä.\n");
			} else {
				strcpy(mjono, tyhja);
				printf("Merkkijono on tyhjennetty.\n");
			}
			break;
		case 3:
			if (koko == 0) {
				printf("Merkkijono on tyhjä.\n");
			} else {
				printf("Merkkijono: %s\n", mjono);
			}
			break;
		case 0:
			printf("Ohjelman lopetus.\n");
			lopeta = 1;
			break;
		default:
			printf("Tuntematon valinta.\n");
			break;
	}
	
}




return 0;
}

/*eof*/
